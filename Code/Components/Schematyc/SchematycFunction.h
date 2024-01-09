#pragma once
/*
	Minimum code for a blank entity component which is visable within the Editor
	1. Change all instances of CBlankComponent AND BlankComponent to a name of your choice.
	2. Don't forget to change the filenames and the include in the .cpp file too
	3. Generate a new GUID (https://docs.cryengine.com/display/CEPROG/Components)
*/
#pragma once

#include <CryEntitySystem/IEntitySystem.h>

class CSchematycFunction final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:
	// Provide a virtual destructor, ensuring correct destruction of IEntityComponent members
	virtual ~CSchematycFunction() = default;

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CSchematycFunction>& desc)
	{
		// Provide a globally unique identifier for the component, can be generated in Visual Studio via Tools -> Create GUID (in registry format).
		desc.SetGUID("{3FA6C213-274A-40AC-9947-94DEECF2645B}"_cry_guid);
		// These set the label and categogory in the editor interface. 
		desc.SetEditorCategory("CryExample Entity");
		desc.SetLabel("Schematyc Function");
	}

	void SetEnabled(const bool& enable);
};