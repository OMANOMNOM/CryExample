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


enum class EEnumClass
{
	Default = 0,
	DifferentValue
};

static void ReflectType(Schematyc::CTypeDesc<EEnumClass>& desc)
{
	desc.SetGUID("{E4DC6A37-2FAE-4DFF-AB21-3C4308A266D6}"_cry_guid);
	desc.SetLabel("Drop down list");
	desc.SetDefaultValue(EEnumClass::Default);
	desc.AddConstant(EEnumClass::Default, "Default", "Default");
	desc.AddConstant(EEnumClass::DifferentValue, "DifferentValue", "DifferentValue");
}



class CEditorVariablesComponent final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:
	struct SEnemyDefinition
	{
		friend class CEnemySpawner;

		static void ReflectType(Schematyc::CTypeDesc<SEnemyDefinition>& desc)
		{
			desc.SetLabel("Enemy Definition");
			desc.SetDescription("Describes an enemy that can be activated/spawned by the spawner component.");
			desc.SetGUID("{267F79B6-66B1-47CE-93C6-A74A0E628289}"_cry_guid);
			desc.AddMember(&SEnemyDefinition::m_enabled, 'enab', "Enabled", "Enabled", "Whether this spawn type is enabled.", false);
			desc.AddMember(&SEnemyDefinition::m_spawnInterval, 'spni', "SpawnInterval", "Spawn Interval", "Time in seconds between each spawn.", 1.f);
		}

		inline bool Serialize(Serialization::IArchive& archive);

		inline bool operator==(const SEnemyDefinition& rhs) const { return 0 == memcmp(this, &rhs, sizeof(rhs)); }
		inline bool operator!=(const SEnemyDefinition& rhs) const { return !(*this == rhs); }

		bool m_enabled = false;

		float m_spawnInterval = 1.f;

	};

	struct SBuoyancyParameters
	{
		inline bool operator==(const SBuoyancyParameters &rhs) const { return 0 == memcmp(this, &rhs, sizeof(rhs)); }

		static void ReflectType(Schematyc::CTypeDesc<SBuoyancyParameters>& desc)
		{
			desc.SetGUID("{2C5EFA87-F7D0-43F1-90B8-576EEB60FC37}"_cry_guid);
			desc.SetLabel("Buoyancy Parameters");
			desc.AddMember(&CEditorVariablesComponent::SBuoyancyParameters::damping, 'damp', "Damping", "Damping", "Uniform damping while submerged, will be scaled with submerged fraction", 0.f);
			desc.AddMember(&CEditorVariablesComponent::SBuoyancyParameters::density, 'dens', "Density", "Density", "Density of the fluid", 1000.f);
			desc.AddMember(&CEditorVariablesComponent::SBuoyancyParameters::resistance, 'rest', "Resistance", "Resistance", "Resistance of the fluid", 1000.f);
		}

		float damping = 0.0f;
		float density = 1000.0f;
		float resistance = 1000.0f;
	};
	// ----------- Basic Entity creation code ----------------
	typedef Schematyc::CArray<SEnemyDefinition> TEnemyList;

	virtual ~CEditorVariablesComponent() = default;

	static void ReflectType(Schematyc::CTypeDesc<CEditorVariablesComponent>& desc)
	{
		desc.SetGUID("{2B4E3DED-948D-44F6-AFCC-0F3B8934793A}"_cry_guid);
		desc.SetEditorCategory("CryExample Entity");
		desc.SetLabel("Editor variables Component");

		// -------------------- Editor reflected varaibles --------------------
		// Here we can specify component varaiables we wish to view and change within the sandbox. No programming required (after being specified in code already)
		desc.AddMember(&CEditorVariablesComponent::importantValue, 'impv', "Important Value", "Important Value", "This is an example variable we can change in the editor", ZERO);
	
		desc.AddMember(&CEditorVariablesComponent::m_type, 'type', "Type", "Type", "Simple Drop down of Possible Enums", EEnumClass::Default);

		desc.AddMember(&CEditorVariablesComponent::m_enemyList, 'elst', "EnemyList", "Enemy List", "List of enemies assigned to the enemy spawner", TEnemyList());

		desc.AddMember(&CEditorVariablesComponent::m_buoyancyParameters, 'buoy', "Buoyancy", "Buoyancy Parameters", "Fluid behavior related to this entity", SBuoyancyParameters());

	}

	// ------------------- Event Stuff ---------------------------------

	// In Cryengine you must tell the engine which events you want a component to have access to. Even an update loop.
	// This is done once upon object creation with the GetEventMask(). You can even change periodiclly which events an object is subscribed to with updateComponentEventMask
	virtual Cry::Entity::EventFlags GetEventMask() const override;
	// All subscribed events are processed by the process event Function. 
	virtual void ProcessEvent(const SEntityEvent& event) override;
	EEnumClass m_type = EEnumClass::Default;
	TEnemyList m_enemyList = TEnemyList();
	SBuoyancyParameters m_buoyancyParameters;



	float importantValue;
};