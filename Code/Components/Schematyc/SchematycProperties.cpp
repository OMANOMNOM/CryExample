#include "StdAfx.h" //Required in all classes to speed up compile
#include "SchematycProperties.h"

#include <CrySchematyc/Env/IEnvRegistrar.h>
#include <CrySchematyc/Env/Elements/EnvComponent.h>
#include <CryCore/StaticInstanceList.h>


static void RegisterSchematycProperties(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(CSchematycProperties));
	}
}


CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterSchematycProperties)

void CSchematycProperties::Initialize()
{
	// Create the Weapon entity attached to the player
	SEntitySpawnParams spawnParams;
	spawnParams.pClass = gEnv->pEntitySystem->GetClassRegistry()->FindClass(m_currentWeapon.value);
	spawnParams.sName = nullptr;
	spawnParams.vPosition = ZERO;
	spawnParams.pParent = m_pEntity;

	if (IEntity* pWeaponEntity = gEnv->pEntitySystem->SpawnEntity(spawnParams))
	{
		m_weaponEntityId = pWeaponEntity->GetId();
		CryLog("%i", m_weaponEntityId);
	}
}
