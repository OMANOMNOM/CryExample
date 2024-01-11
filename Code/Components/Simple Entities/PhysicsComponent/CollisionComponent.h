#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include <DefaultComponents/Physics/RigidBodyComponent.h>


/// <summary>
/// For an entity to check for physics collisions it must be a ridigid body, and be physicalized
/// Then you can check for collisions with the event system.
/// </summary>
class CCollisionComponent final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:
	// Provide a virtual destructor, ensuring correct destruction of IEntityComponent members
	virtual ~CCollisionComponent() = default;

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CCollisionComponent>& desc)
	{
		// Provide a globally unique identifier for the component, can be generated in Visual Studio via Tools -> Create GUID (in registry format).
		desc.SetGUID("{3C16E31F-E93A-45D0-88DD-C743E1494AB4}"_cry_guid);
		// These set the label and categogory in the editor interface. 
		desc.SetEditorCategory("CryExample Entity");
		desc.SetLabel("Collision Component");
	}
	virtual void Initialize() override;

	// rigidbody
	// Somekind of charactermodel
	Cry::DefaultComponents::CRigidBodyComponent* m_pRigidbodyComponent = nullptr;

	virtual Cry::Entity::EventFlags GetEventMask() const override;
	// All subscribed events are processed by the process event Function. 
	virtual void ProcessEvent(const SEntityEvent& event) override;


};