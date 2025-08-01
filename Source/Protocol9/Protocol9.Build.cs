// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Protocol9 : ModuleRules
{
	public Protocol9(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "AIModule","NavigationSystem","Niagara"});

		PrivateDependencyModuleNames.AddRange(new string[] { "AIModule", "NavigationSystem","Niagara"});


		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
