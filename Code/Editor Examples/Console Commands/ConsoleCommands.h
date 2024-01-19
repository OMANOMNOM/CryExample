#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include <CrySystem/IConsole.h>

class CConsoleCommandsExample final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:
	// Provide a virtual destructor, ensuring correct destruction of IEntityComponent members
	virtual ~CConsoleCommandsExample() = default;

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CConsoleCommandsExample>& desc)
	{
		// Provide a globally unique identifier for the component, can be generated in Visual Studio via Tools -> Create GUID (in registry format).
		desc.SetGUID("{BD19BFA3-2AC8-423C-B01F-94F40B067D5E}"_cry_guid);
		// These set the label and categogory in the editor interface. 
		desc.SetEditorCategory("CryExample Editor");
		desc.SetLabel("Console Commmands Example");
	}

	virtual void Initialize() override;
	void RegisterCommand();

	void UnregisterCommand();

};