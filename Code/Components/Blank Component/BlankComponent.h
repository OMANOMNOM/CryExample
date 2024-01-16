/*	
	Minimum code for a blank entity component which is visable within the Editor
	1. Change all instances of CBlankComponent AND BlankComponent to a name of your choice.
	2. Don't forget to change the filenames and the include in the .cpp file too
	3. Generate a new GUID (https://docs.cryengine.com/display/CEPROG/Components)
*/
#pragma once

#include <CryEntitySystem/IEntitySystem.h>

class CBlankComponent final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:
	// Provide a virtual destructor, ensuring correct destruction of IEntityComponent members
	virtual ~CBlankComponent() = default;

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CBlankComponent>& desc)
	{
		// Provide a globally unique identifier for the component, can be generated in Visual Studio via Tools -> Create GUID (in registry format).
		desc.SetGUID("{2AEF0B0A-B12E-4286-9B7B-A032277F93CA}"_cry_guid);
		// These set the label and categogory in the editor interface. 
		desc.SetEditorCategory("CryExample Entity");
		desc.SetLabel("BlankComponent");
	}

};