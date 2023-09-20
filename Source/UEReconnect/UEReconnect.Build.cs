// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEReconnect : ModuleRules
{
	public UEReconnect(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks"
		});
		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"HeadMountedDisplay",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks"
		});
	}
}