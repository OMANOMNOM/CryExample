#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include <CrySchematyc/ResourceTypes.h> // Look in this file for default schematyc types we can use in code. 
class CSchematycProperties final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:
	// Provide a virtual destructor, ensuring correct destruction of IEntityComponent members
	virtual ~CSchematycProperties() = default;

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CSchematycProperties>& desc)
	{
		// Provide a globally unique identifier for the component, can be generated in Visual Studio via Tools -> Create GUID (in registry format).
		desc.SetGUID("{75052962-F3AA-481F-A875-A5C1053BA9E7}"_cry_guid);
		// These set the label and categogory in the editor interface. 
		desc.SetEditorCategory("CryExample Schematyc");
		desc.SetLabel("Schematyc Properties");

		desc.AddMember(&CSchematycProperties::m_currentWeapon, 'cwep', "CurrentWeapon", "Current Weapon", "The current weapon this weapon attachment is holding.", "");
	}

	virtual void Initialize() override;
public:
	Schematyc::EntityClassName m_currentWeapon = "";
	EntityId m_weaponEntityId = INVALID_ENTITYID;

};