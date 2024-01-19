#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include <CryEntitySystem/IEntityComponent.h>
#include <CrySchematyc/ResourceTypes.h>

/// <summary>
/// You can make more than intergral/floating/string types appear in components panel in the editor. 
/// For more complex types such as the struct below you must reflec it as shown. 
/// See TypeDesc.h for more infomation on reflecting types. 
/// </summary>
class CGroupedComponentProperties final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:
	
	// 1. We define the struct and reflect it and its members
	struct SReflectedStruct
	{
		inline bool operator==(const SReflectedStruct &rhs) const { return 0 == memcmp(this, &rhs, sizeof(rhs)); }

		static void ReflectType(Schematyc::CTypeDesc<SReflectedStruct>& desc)
		{

			desc.SetGUID("{2C5EFA87-F7D0-43F1-90B8-576EEB60FC37}"_cry_guid);
			desc.SetLabel("Editable struct");
			desc.AddMember(&CGroupedComponentProperties::SReflectedStruct::m_ImportantValue1, 'damp', "Damping", "Damping", "Uniform damping while submerged, will be scaled with submerged fraction", 0.f);
			desc.AddMember(&CGroupedComponentProperties::SReflectedStruct::m_ImportantValue2, 'dens', "Density", "Density", "Density of the fluid", 1000.f);
			desc.AddMember(&CGroupedComponentProperties::SReflectedStruct::m_ImportantValue3, 'rest', "Resistance", "Resistance", "Resistance of the fluid", 1000.f);
		}

		float m_ImportantValue1 = 0.0f;
		float m_ImportantValue2 = 1000.0f;
		float m_ImportantValue3 = 1000.0f;
	};

	virtual ~CGroupedComponentProperties() = default;

	static void ReflectType(Schematyc::CTypeDesc<CGroupedComponentProperties>& desc)
	{
		desc.SetGUID("{02AA4072-A909-4A6F-A3CB-B67F1BE86277}"_cry_guid);
		desc.SetEditorCategory("CryExample Entity");
		desc.SetLabel("CryExample EntityComponent basics");

		// -------------------- Editor reflected varaibles --------------------
		// Here we can specify component varaiables we wish to view and change within the sandbox. No programming required (after being specified in code already)
		desc.AddMember(&CGroupedComponentProperties::m_importantValue, 'impv', "Important Value", "Important Value", "This is an example variable we can change in the editor", ZERO);
	
		// 2. This adds the SBuoyancyParams component properties as a gruop of properties
		desc.AddMember(&CGroupedComponentProperties::m_buoyancyParameters, 'buoy', "Buoyancy", "Buoyancy Parameters", "Fluid behavior related to this entity", SReflectedStruct());

	}

	// ------------------- Components member varaibles ---------------------------------

	// 3. The struct we want added to the component
	SReflectedStruct m_buoyancyParameters;

	// A float we want to make editrable within the editor
	float m_importantValue;
};