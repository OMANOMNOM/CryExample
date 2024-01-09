#pragma once
/*
	Minimum code for a blank entity component which is visable within the Editor
	1. Change all instances of CBlankComponent AND BlankComponent to a name of your choice.
	2. Don't forget to change the filenames and the include in the .cpp file too
	3. Generate a new GUID (https://docs.cryengine.com/display/CEPROG/Components)
*/
#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include <CrySchematyc/ResourceTypes.h>
#include <CrySchematyc/Utils/SharedString.h>


struct SSignalEnemySpawned
{
	SSignalEnemySpawned() = default;
	SSignalEnemySpawned(const Schematyc::CSharedString& spawnId)
		: m_spawnId(spawnId)
	{}

	Schematyc::CSharedString m_spawnId = "";
};


class CSchematycSignal final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:
	// Provide a virtual destructor, ensuring correct destruction of IEntityComponent members
	virtual ~CSchematycSignal() = default;

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CSchematycSignal>& desc)
	{
		// Provide a globally unique identifier for the component, can be generated in Visual Studio via Tools -> Create GUID (in registry format).
		desc.SetGUID("{DCC6073F-ACED-4BC5-9700-58AB9B4535E0}"_cry_guid);
		// These set the label and categogory in the editor interface. 
		desc.SetEditorCategory("CryExample Entity");
		desc.SetLabel("Schematyc Signal");
	}
	void Spawn() const;
};

static void ReflectType(Schematyc::CTypeDesc<SSignalEnemySpawned>& desc)
{
	desc.SetGUID("{6904FAA4-7587-477E-8F7F-E9BFE60B97CD}"_cry_guid);
	desc.SetLabel("Enemy Spawned");
	desc.AddMember(&SSignalEnemySpawned::m_spawnId, 'spwn', "SpawnId", "Spawn Id", "The identifier of the enemy that was spawned.", "");
}