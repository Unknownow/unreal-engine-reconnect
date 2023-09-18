// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestNetworkProject : ModuleRules
{
	public TestNetworkProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
