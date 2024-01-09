/*	
	Minimum code for a blank entity component which is visable within the Editor
	1. Copy BlankEntity to your code folder
	2. Add to VS project, then build ZERO_CHECK
	3. Change all instances of CBlankComponent AND BlankComponent to a name of your choice.
	4. Don't forget to change the filenames and the include in the .cpp file too
	5. Generate a new GUID (https://docs.cryengine.com/display/CEPROG/Components)
*/
#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include <CryEntitySystem/IEntityComponent.h>
#include <CrySchematyc/ResourceTypes.h>






class CSimpleComponentProperty final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:

	virtual ~CSimpleComponentProperty() = default;

	static void ReflectType(Schematyc::CTypeDesc<CSimpleComponentProperty>& desc)
	{
		desc.SetGUID("{2B4E3DED-948D-44F6-AFCC-0F3B8934793A}"_cry_guid);
		desc.SetEditorCategory("CryExample Entity");
		desc.SetLabel("Simple Component Property");

		// -------------------- Editor reflected varaibles --------------------
		// Here we can specify component varaiables we wish to view and change within the sandbox. No programming required (after being specified in code already)
		desc.AddMember(&CSimpleComponentProperty::m_importantValue, 'impv', "ImportantValue", "Important Value", "This is an example variable we can change in the editor", ZERO);


	}

	// ------------------- Event Stuff ---------------------------------

	// In Cryengine you must tell the engine which events you want a component to have access to. Even an update loop.
	// This is done once upon object creation with the GetEventMask(). You can even change periodiclly which events an object is subscribed to with updateComponentEventMask
	virtual Cry::Entity::EventFlags GetEventMask() const override;
	// All subscribed events are processed by the process event Function. 
	virtual void ProcessEvent(const SEntityEvent& event) override;

	float m_importantValue;
};