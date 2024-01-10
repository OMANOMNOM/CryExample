#pragma once

#include <CryEntitySystem/IEntitySystem.h>

/// <summary>
/// Demonstrates how to Create a Schematyc Function node for the entity. (C++ function callable from schematyc)
/// </summary>
class CSchematycFunction final : public IEntityComponent

{
public:
	// Provide a virtual destructor, ensuring correct destruction of IEntityComponent members
	virtual ~CSchematycFunction() = default;

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<CSchematycFunction>& desc)
	{
		// Provide a globally unique identifier for the component, can be generated in Visual Studio via Tools -> Create GUID (in registry format).
		desc.SetGUID("{3FA6C213-274A-40AC-9947-94DEECF2645B}"_cry_guid);
		// These set the label and categogory in the editor interface. 
		desc.SetEditorCategory("CryExample Entity");
		desc.SetLabel("Schematyc Function");
	}

	// Our function which we can call from schematyc
	void SetEnabled(const bool& enable);
};