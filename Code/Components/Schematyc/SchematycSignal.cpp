#include "StdAfx.h" //Required in all classes to speed up compile
#include "Components/Schematyc/SchematycSignal.h"

#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>

// 
#include <CrySchematyc/Env/Elements/EnvSignal.h>
#include <CrySystem/ISystem.h>
#include <CryEntitySystem/IEntitySystem.h>
#include <CryMath/Random.h>
#include <CryMath/Cry_Math.h>

#include <CryCore/StaticInstanceList.h>
#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CrySchematyc/Env/Elements/EnvFunction.h>
#include <CrySchematyc/Env/Elements/EnvSignal.h>
#include <CrySchematyc/IObject.h>
// ------------ Not sure you need these for a simple entity ------------
//#include <CrySchematyc/Reflection/TypeDesc.h>
//#include <CrySchematyc/Utils/EnumFlags.h>
//#include <CrySchematyc/Env/IEnvRegistry.h>
//#include <CrySchematyc/Env/Elements/EnvFunction.h>
//#include <CrySchematyc/Env/Elements/EnvSignal.h>
//#include <CrySchematyc/ResourceTypes.h>
//#include <CrySchematyc/MathTypes.h>
//#include <CrySchematyc/Utils/SharedString.h>

// Makes the component 'editable' within the CE editor. 
static void RegisterSchematycSignal(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CSchematycSignal));

		{
			componentScope.Register(SCHEMATYC_MAKE_ENV_SIGNAL(SSignalEnemySpawned));
		}
	}
}


CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterSchematycSignal)



inline void CSchematycSignal::Spawn() const
{
		if (Schematyc::IObject* pSchematycObject = m_pEntity->GetSchematycObject())
		{
			pSchematycObject->ProcessSignal(static_cast<const SSignalEnemySpawned&>(SSignalEnemySpawned("bla bla bla")), GetGUID());
		}
	
}
