// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TP2_unreal : ModuleRules
{
	public TP2_unreal(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
