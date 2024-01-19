/*	
	Minimum code for a blank entity component which is visable within the Editor
	1. Change all instances of CBlankComponent AND BlankComponent to a name of your choice.
	2. Don't forget to change the filenames and the include in the .cpp file too
	3. Generate a new GUID (https://docs.cryengine.com/display/CEPROG/Components)
*/
#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include <CryEntitySystem/IEntityComponent.h>

class CTimerComponentExample final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:
	// Provide a virtual destructor, ensuring correct destruction of IEntityComponent members
	virtual ~CTimerComponentExample() = default;

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CTimerComponentExample>& desc)
	{
		// Provide a globally unique identifier for the component, can be generated in Visual Studio via Tools -> Create GUID (in registry format).
		desc.SetGUID("{B724A4FB-1A18-4601-99A0-9118BA74CA95}"_cry_guid);
		// These set the label and categogory in the editor interface. 
		desc.SetEditorCategory("CryExample EntityComponent basics");
		desc.SetLabel("Timer Example");
	}


// In Cryengine you must tell the engine which events you want a component to have access to. Even an update loop.
// This is done once upon object creation with the GetEventMask(). You can even change periodiclly which events an object is subscribed to with updateComponentEventMask
	virtual Cry::Entity::EventFlags GetEventMask() const override;
	// All subscribed events are processed by the process event Function. 
	virtual void ProcessEvent(const SEntityEvent& event) override;

};