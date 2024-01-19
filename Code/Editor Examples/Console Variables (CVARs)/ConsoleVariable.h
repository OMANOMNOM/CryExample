#pragma once

#include <CryEntitySystem/IEntitySystem.h>

class CConsoleVaraibleExample final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:
	// Provide a virtual destructor, ensuring correct destruction of IEntityComponent members
	~CConsoleVaraibleExample();
	CConsoleVaraibleExample();

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CConsoleVaraibleExample>& desc)
	{
		// Provide a globally unique identifier for the component, can be generated in Visual Studio via Tools -> Create GUID (in registry format).
		desc.SetGUID("{7B8B5F6D-0E95-4431-BAF8-651D55AA6E88}"_cry_guid);
		// These set the label and categogory in the editor interface. 
		desc.SetEditorCategory("CryExample Editor");
		desc.SetLabel("Console Variable Example");
	}

	int specialNumber;
};