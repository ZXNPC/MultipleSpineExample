## 项目简介

此项目为b站文章 [[UE5/Spine] 如何在一张蓝图中导入多个Spine角色](https://www.bilibili.com/read/cv25607067/) 的演示项目，在
SpinePlugin 中实现了一个 SpineCharacter 类来演示“如何在一个蓝图中放入两个Spine角色”

## 版本信息

- UE 5.1.1
- Spine 4.1.24
- [Spine-runtime 4.1](https://github.com/EsotericSoftware/spine-runtimes "点击查看 Github")

## 分析原因

**SpinePlugin 是如何运作的**

在 *Plugins/SpinePlugin/Source/SpinePlugin/Private/SpineSkeletonRendererComponent.cpp* 中的 `TickComponent()` 方法中：

```c++
void USpineSkeletonRendererComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor *owner = GetOwner(); 
    if (owner) {
        UClass *skeletonClass = USpineSkeletonComponent::StaticClass();
        USpineSkeletonComponent *skeletonComponent = Cast<USpineSkeletonComponent>(owner->GetComponentByClass(skeletonClass));
        
        UpdateRenderer(skeletonComponent);
    }
}
```

也就是说在每一 Tick SpineRenderer（以下简称 `Renderer`） 都去寻找此 Actor 上的**第一个** SpineSkeletonComponent （也就是
SpineSkeletonAnimation，以下简称 `Animation`）， 并调用 `UpdateRenderer()` 方法更新 Spine
角色，因此只需要事先指定 `Animation` 即可放入多个角色

## 解决方法
**修改 SpinePlugin 代码实现**

1. *Plugins/SpinePlugin/Source/SpinePlugin/Public/SpineSkeletonRendererComponent.h* 中添加公开变量 `SkeletonComponent`
2. *Plugins/SpinePlugin/Source/SpinePlugin/Private/SpineSkeletonRendererComponent.cpp* 中修改 `TickComponent()`
    ```c++
    void USpineSkeletonRendererComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) {
        Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
        // SpineSkeletonComponent is initialized at owner
        if (SkeletonComponent) {
            UpdateRenderer(SkeletonComponent);
        }
    }
    ```
3. 在 `ACharacter` 子类的构建方法中设置 `SkeletonComponent`，例子如 *Source/MultipleSpineExample/SpineCharacter.h*