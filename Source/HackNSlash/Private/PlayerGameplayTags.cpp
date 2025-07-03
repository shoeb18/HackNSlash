// CopyNinja All Rights Reserved


#include "PlayerGameplayTags.h"



namespace PlayerGameplayTags
{
	/* Input Tags */
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipSword, "InputTag.EquipSword");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipSword, "InputTag.UnequipSword");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack_Sword, "InputTag.LightAttack.Sword");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack_Sword, "InputTag.HeavyAttack.Sword");

	/* Player Tags */
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Sword, "Player.Weapon.Sword");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Sword, "Player.Ability.Equip.Sword");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Sword, "Player.Ability.Unequip.Sword");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Sword, "Player.Ability.Attack.Light.Sword");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Sword, "Player.Ability.Attack.Heavy.Sword");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Sword, "Player.Event.Equip.Sword");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_Sword, "Player.Event.Unequip.Sword");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_JumpToFinisher, "Player.Status.JumpToFinisher");

	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackType_Light, "Player.SetByCaller.AttackType.Light");
	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_AttackType_Heavy, "Player.SetByCaller.AttackType.Heavy");

	/* Enemy Tags */
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Weapon, "Enemy.Weapon");

	/* Shared Tags */
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_Melee_Hit, "Shared.Event.Melee.Hit");

	UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_BaseDamage, "Shared.SetByCaller.BaseDamage");
}