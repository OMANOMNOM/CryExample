#pragma once

#include <CryEntitySystem/IEntitySystem.h>

class CRaycastingExample final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:
	// Provide a virtual destructor, ensuring correct destruction of IEntityComponent members
	virtual ~CRaycastingExample() = default;

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CRaycastingExample>& desc)
	{
		// Provide a globally unique identifier for the component, can be generated in Visual Studio via Tools -> Create GUID (in registry format).
		desc.SetGUID("{C24851A7-619F-469F-A1BB-F2C0330E5F52}"_cry_guid);
		// These set the label and categogory in the editor interface. 
		desc.SetEditorCategory("CryExample Physics");
		desc.SetLabel("Raycasting Component");
	}

	virtual Cry::Entity::EventFlags GetEventMask() const override;
	// All subscribed events are processed by the process event Function. 
	virtual void ProcessEvent(const SEntityEvent& event) override;
	
	bool m_isRaycasting = false;
	void raycast();
};