#pragma once

#include <CryEntitySystem/IEntitySystem.h>
#include <DefaultComponents/Input/InputComponent.h>


// Names this CInputEntity to avoid confusion with the CInputComponent
class CInputEntity final : public IEntityComponent // Best practice: Classes start with a 'C'

{
public:
	// Provide a virtual destructor, ensuring correct destruction of IEntityComponent members
	virtual ~CInputEntity() = default;
	virtual void Initialize() override;
	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CInputEntity>& desc)
	{
		// Provide a globally unique identifier for the component, can be generated in Visual Studio via Tools -> Create GUID (in registry format).
		desc.SetGUID("{E6D7CAEC-33E9-448C-A2CF-BE3C0C844FBA}"_cry_guid);
		// These set the label and categogory in the editor interface. 
		desc.SetEditorCategory("CryExample EntityComponent basics");
		desc.SetLabel("Input Example");
	}

	Cry::DefaultComponents::CInputComponent* m_pInputComponent = nullptr;


};