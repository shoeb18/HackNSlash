#pragma once


UENUM()
enum class ECharacterConfirmType : uint8
{
	Yes,
	No,
};

UENUM()
enum class ECharacterValidType : uint8
{
	Valid,
	Invalid,
};

UENUM()
enum class ECharacterSuccessType : uint8
{
	Successful,
	Failed,
};