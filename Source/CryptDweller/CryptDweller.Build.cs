// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CryptDweller : ModuleRules
{
	public CryptDweller(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
