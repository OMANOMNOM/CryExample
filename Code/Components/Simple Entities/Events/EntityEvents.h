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


class CEntityEventsComponent final : public IEntityComponent // Best practice: Classes start with a 'C'

{
	// ----------- Basic Entity creation code ----------------
public:
	virtual ~CEntityEventsComponent() = default;

	static void ReflectType(Schematyc::CTypeDesc<CEntityEventsComponent>& desc)
	{
		desc.SetGUID("{174B2D8F-2B15-4BF1-8091-505049307B39}"_cry_guid);
		desc.SetEditorCategory("EntityEventsComponent");
		desc.SetLabel("Entity Events Component");
	}

	// ------------------- Event Stuff ---------------------------------

	// In Cryengine you must tell the engine which events you want a component to have access to. Even an update loop.
	// This is done once upon object creation with the GetEventMask(). You can even change periodiclly which events an object is subscribed to with updateComponentEventMask
	virtual Cry::Entity::EventFlags GetEventMask() const override;
	// All subscribed events are processed by the process event Function. 
	virtual void ProcessEvent(const SEntityEvent& event) override;
	
};