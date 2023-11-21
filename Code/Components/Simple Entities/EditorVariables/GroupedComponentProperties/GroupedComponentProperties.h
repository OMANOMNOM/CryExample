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


class CGroupedComponentProperties final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:
	
	struct SBuoyancyParameters
	{
		inline bool operator==(const SBuoyancyParameters &rhs) const { return 0 == memcmp(this, &rhs, sizeof(rhs)); }

		static void ReflectType(Schematyc::CTypeDesc<SBuoyancyParameters>& desc)
		{
			desc.SetGUID("{2C5EFA87-F7D0-43F1-90B8-576EEB60FC37}"_cry_guid);
			desc.SetLabel("Buoyancy Parameters");
			desc.AddMember(&CGroupedComponentProperties::SBuoyancyParameters::damping, 'damp', "Damping", "Damping", "Uniform damping while submerged, will be scaled with submerged fraction", 0.f);
			desc.AddMember(&CGroupedComponentProperties::SBuoyancyParameters::density, 'dens', "Density", "Density", "Density of the fluid", 1000.f);
			desc.AddMember(&CGroupedComponentProperties::SBuoyancyParameters::resistance, 'rest', "Resistance", "Resistance", "Resistance of the fluid", 1000.f);
		}

		float damping = 0.0f;
		float density = 1000.0f;
		float resistance = 1000.0f;
	};

	virtual ~CGroupedComponentProperties() = default;

	static void ReflectType(Schematyc::CTypeDesc<CGroupedComponentProperties>& desc)
	{
		desc.SetGUID("{02AA4072-A909-4A6F-A3CB-B67F1BE86277}"_cry_guid);
		desc.SetEditorCategory("CryExample Entity");
		desc.SetLabel("Grouped Component Properties");

		// -------------------- Editor reflected varaibles --------------------
		// Here we can specify component varaiables we wish to view and change within the sandbox. No programming required (after being specified in code already)
		desc.AddMember(&CGroupedComponentProperties::m_importantValue, 'impv', "Important Value", "Important Value", "This is an example variable we can change in the editor", ZERO);
	
		// This adds the SBuoyancyParams component properties as a gruop of properties
		desc.AddMember(&CGroupedComponentProperties::m_buoyancyParameters, 'buoy', "Buoyancy", "Buoyancy Parameters", "Fluid behavior related to this entity", SBuoyancyParameters());

	}

	// ------------------- Event Stuff ---------------------------------

	// In Cryengine you must tell the engine which events you want a component to have access to. Even an update loop.
	// This is done once upon object creation with the GetEventMask(). You can even change periodiclly which events an object is subscribed to with updateComponentEventMask
	virtual Cry::Entity::EventFlags GetEventMask() const override;
	// All subscribed events are processed by the process event Function. 
	virtual void ProcessEvent(const SEntityEvent& event) override;
	SBuoyancyParameters m_buoyancyParameters;


	float m_importantValue;
};