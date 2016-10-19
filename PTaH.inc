#if defined _PTaH_included
  #endinput
#endif
#define _PTaH_included

enum PTaH_Hook
{
	Hook,
	UnHook
};

enum PTaH_HookType
{
	PTaH_GiveNamedItem = 0,
	PTaH_GiveNamedItemPre,
	PTaH_WeaponCanUse,
	PTaH_SetPlayerModel,
	PTaH_SetPlayerModelPre,
	PTaH_ConsolePrint,
	PTaH_MapContentList,
	PTaH_OnClientConnect,
	PTaH_ExecuteStringCommand
};

enum EStickerAttributeType 
{ 
    StickerID,
    WearProgress,
    PatternScale,
    PatternRotation 
};

methodmap CEconItemDefinition
{
	//!!!!!!!!!!!!!!!!!!!!! CEconItemDefinition не является Handle, CloseHandle() - НЕ НУЖЕН !!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!! Всегда проверяйте, не равен ли CEconItemDefinition - NULL ( if(ItemDefinition) ) !!!!!!!!!!!!!!!!!!!!!

	/**
	 *	Получает DefinitionIndex.
	 *	-
	 * @return	Возвращает DefinitionIndex.
	 *	-
	 * @error CEconItemDefinition == NULL.
	*/
	public native int GetDefinitionIndex();
	
	/**
	 *	Получает LoadoutSlot.
	 * @param def			значение по умолчанию.
	 *	-
	 * @return	Возвращает LoadoutSlot.
	 *	-
	 * @error CEconItemDefinition == NULL.
	*/
	public native int GetLoadoutSlot(int def = -1);
	
	/**
	 *	Получает колиество слотов под Sticker.
	 *	-
	 * @return	Возвращает StickerSlotsCount.
	 *	-
	 * @error CEconItemDefinition == NULL.
	*/
	public native int GetNumSupportedStickerSlots();
};

methodmap CEconItemView
{
	//!!!!!!!!!!!!!!!!!!!!! CEconItemView не является Handle, CloseHandle() - НЕ НУЖЕН !!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!! Всегда проверяйте, не равен ли CEconItemDefinition - NULL ( if(ItemDefinition) ) !!!!!!!!!!!!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!! Не храните глобально CEconItemView иначе если игрок выйдет то после вызова функции вы получете Crash сервера !!!!!!!!!!!!!!!!!!!!!
	
	/**
	 *	Получает индекс скина оружия.
	 *	-
	 * @return	Возвращает PaintKitIndex.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public native int GetCustomPaintKitIndex();
	
	/**
	 *	Получает смещение скина оружия.
	 *	-
	 * @return	Возвращает PaintKitSeed.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public native int GetCustomPaintKitSeed();
	
	/**
	 *	Получает качество скина оружия.
	 * @param def			значение по умолчанию.
	 *	-
	 * @return	Возвращает PaintKitWear.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public native float GetCustomPaintKitWear(float def = -1.0);
	
	/**
	 *	Получает значение атрибута по номеру слота Sticker.
	 * @param iSlot			индекс слота.
	 * @param ESAT			атрибут.
	 * @param def			значение по умолчанию.
	 *	-
	 * @return	Возвращает StickerAttribute.
	 *	-
	 * @error CEconItemView == NULL.
	 * -
	 * StickerID - возращает int, def тоже нужно передавать int
	 * WearProgress, PatternScale, PatternRotation - возращает float, def тоже нужно передавать float
	*/
	public native any GetStickerAttributeBySlotIndex(int iSlot, EStickerAttributeType ESAT, any def);
	
	/**
	 *	Провека: Можно ли обменивать оружие
	 *	-
	 * @return	Возвращает Tradable.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public native bool IsTradable();
	
	/**
	 *	Проверка: Можно ли продать оружие - http://steamcommunity.com/market/
	 *	-
	 * @return	Возвращает Marketable.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public native bool IsMarketable();
	
	/**
	 *	Получает ItemDefinition.
	 *	-
	 * @return	Возвращает CEconItemDefinition.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public native CEconItemDefinition GetItemDefinition();
	
	/**
	 *	Получает AccountID владельца скина (сверить можно по GetSteamAccountID).
	 *	-
	 * @return	Возвращает AccountID.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public native int GetAccountID();
	
	/**
	 *	Получает индекс владельца оружия.
	 *	-
	 * @return	Возвращает iClient.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public int GetClientIndex() 
    { 
		int AccountID = this.GetAccountID();
		for (int i = 1; i <= MaxClients; i++) if(IsClientInGame(i) && AccountID == GetSteamAccountID(i)) return i;
		return 0;
    }
	
	/**
	 *	Получает кастюмный ли ItemView.
	 *	-
	 * @return	Возвращает IsCustom.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public bool IsCustomItemView() 
    { 
		return this.GetAccountID() != 0 ? true:false;
    }
	
	/**
	 *	Получает Quality скина.
	 *	-
	 * @return	Возвращает Quality.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public native int GetQuality();
	
	/**
	 *	Получает Rarity скина.
	 *	-
	 * @return	Возвращает Rarity.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public native int GetRarity();
	
	/**
	 *	Получает Flags скина.
	 *	-
	 * @return	Возвращает Flags.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public native int GetFlags();
	
	/**
	 *	Получает Origin скина.
	 *	-
	 * @return	Возвращает Origin.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public native int GetOrigin();
	
	/**
	 *	Получает Неймтег скина.
	 * @param sBuf			строка.
	 * @param iLen			размер строки (максимальная длина, которая может быть - 161).
	 *	-
	 * @return	Возвращает длину Неймтега.
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public native int GetCustomName(char[] sBuf, int iLen);
	
	/**
	 *	Получает количество StatTrak.
	 *	-
	 * @return	Возвращает количество StatTrak (если StatTrak = -1 значит его нет).
	 *	-
	 * @error CEconItemView == NULL.
	*/
	public native int GetStatTrakKill();
};

typeset PTaHCB
{
	/** GiveNamedItem
	 *
	 *	Вызывается когда игрок получает предмет.
	 *	-
	 * @param iClient			Индекс игрока.
	 * @param sClassname		Класснейм предмета.
	 * @param Item				Кастюмизация предмета.
	 * @param iEnt				Индекс Ентити предмета.
	 *	-
	 * @noreturn
	*/
	function void (int iClient, const char[] sClassname, const CEconItemView Item, int iEnt);
	
	/** GiveNamedItemPre
	 *
	 *	Вызывается перед выдачей предмета.
	 *	-
	 * @param iClient			Индекс игрока.
	 * @param sClassname		Класснейм оружия.
	 * @param Item				Кастюмизация предмета.
	 *	-
	 * @return	Возврат Plugin_Stop или Plugin_Handled остановит выдачу предмета. Возврат Plugin_Continue разрешит выдачу предмета без изменений. Возврат Plugin_Changed разрешит выдачу примета с изминениями.
	*/
	function Action (int iClient, char sClassname[64], CEconItemView &Item);
	
	/** WeaponCanUse
	 *
	 *	Вызывается когда игрок пытается поднять предмет.
	 *	-
	 * @param iClient			Индекс игрока.
	 * @param iEnt				Индекс Ентити предмета.
	 * @param CanUse			Для возврата без изменений.
	 *	-
	 * @return	Возврат false запретит подъем предмета. Возврат CanUse вернет ответ без изменений. Возврат true разрешит подъем предмета.
	*/
	function bool (int iClient, int iEnt, bool CanUse);
	
	/** SetPlayerModel
	 *
	 *	Вызывается после смены модели игроку.
	 *	-
	 * @param iClient			Индекс игрока.
	 * @param sModel			Путь к модели.
	 *	-
	 * @noreturn
	*/
	function void (int iClient, const char[] sModel);
	
	/** SetPlayerModelPre
	 *
	 *	Вызывается перед сменой модели игроку.
	 *	-
	 * @param iClient			Индекс игрока.
	 * @param sModel			Путь к текущей модели игрока.
	 * @param sNewModel			Путь к новой модели.
	 *	-
	 * @return	Возврат Plugin_Stop или Plugin_Handled остановит смену модели. Возврат Plugin_Continue разрешит смену модели без изменений. Возврат Plugin_Changed разрешит смену на измененную модель.
	*/
	function Action (int iClient, const char[] sModel, char sNewModel[128]);
	
	/** ConsolePrint/ExecuteStringCommand
	 * ConsolePrint
	 *
	 *	Вызывается перед выводом сообщения в консоль игроку.
	 *	-
	 * @param iClient			Индекс игрока.
	 * @param sMessage			Текст сообщения.
	 *	-
	 * @return	Возврат Plugin_Stop или Plugin_Handled запретит вывод сообщения. Возврат Plugin_Continue разрешит вывод сообщения без изменений. Возврат Plugin_Changed разрешит вывод измененного сообщения.
	 *	-
	 * ExecuteStringCommand
	 *
	 *	Вызывается перед выполнением команды игрока на сервере.
	 *	-
	 * @param iClient			Индекс игрока.
	 * @param sMessage			Команда.
	 *	-
	 * @return	Возврат Plugin_Stop или Plugin_Handled запретит выполнение. Возврат Plugin_Continue разрешит выполнение без изменений. Возврат Plugin_Changed разрешит выполнение с изенениями.
	*/
	function Action (int iClient, char sMessage[512]);
	
	/** MapContentList
	 *
	 *	Вызывается перед созданием контента карты который будет добавлен в скачку(AddFileToDownloadsTable не вызывает данное событие).
	 *	-
	 * @param sFile				Путь к файлу который будет добавлен в скачку.
	 *	-
	 * @return	Возврат Plugin_Stop или Plugin_Handled запретит добавление контента в скачку. Возврат Plugin_Continue разрешит добавление контента в скачку без изменений. Возврат Plugin_Changed разрешит добавление контента в скачку с изменением.
	*/
	function Action (char sFile[128]);	
	
	/** OnClientConnect
	 *
	 *	Вызывается перед авторизацией клиента на сервере.
	 *	-
	 * @param sName				Никнейм клиента.
	 * @param sPassword			Пароль который он ввел.
	 * @param sIp				IP клиента.
	 * @param sSteamID			SteamID (2 версии) клиента.
	 * @param rejectReason		Причина неавторизации.
	 *	-
	 * @return	Возврат Plugin_Stop или Plugin_Handled запретит авторизацию клиента. Возврат Plugin_Continue разрешит авторизацию без изменений. Возврат Plugin_Changed разрешит авторизацию с изменением.
	*/
	function Action (const char[] sName, char sPassword[128], const char[] sIp, const char[] sSteamID, char rejectReason[512]);
};

/**
 *	Активирует хук.
 * @param type					Тип хука.
 * @param hk					Hook/UnHook.
 * @param callback				Обратный вызов.
 *	-
 * @return	Возвращает true в случае удачи, иначе false.
*/
native bool PTaH(PTaH_HookType type, PTaH_Hook hk, PTaHCB callback);

/**
 *	Получает CEconItemDefinition из ClassName оружия.
 * @param sClassName					ClassName оружия.
 *	-
 * @return	Возвращает CEconItemDefinition.
*/
native CEconItemDefinition PTaH_GetItemDefinitionByName(const char[] sClassName);

/**
 *	Получает CEconItemView оружия клиента.
 * @param iClient					Индекс клиента.
 * @param iTeam						Индекс команды.
 * @param iLoadoutSlot				Индекс слота оружия.
 *	-
 * @return	Возвращает CEconItemDefinition.
 *	-
 * @error невалдный iClient, !(2 <= iTeam <= 3).
*/
native CEconItemView PTaH_GetItemInLoadout(int iClient, int iTeam, int iLoadoutSlot);

/**
 *	Получает CEconItemView оружия.
 * @param iEnt					Индекс оружия.
 *	-
 * @return	Возвращает CEconItemDefinition.
 *	-
 * @error невалдный iEnt, iEnt не является оружием.
*/
native CEconItemView PTaH_GetEconItemViewFromWeapon(int iEnt);

/**
 *	Выдает игроку предмет с указанным CEconItemView.
 * @param iClient				Индекс игрока.
 * @param sClassname			Класнейм предмета.
 * @param Item					Кастюмизация предмета.
 *	-
 * @return	Возвращает индекс предмета.
 *	-
 * @error невалдный iClient.
*/
native int PTaH_GivePlayerItem(int iClient, const char[] sClassname, CEconItemView Item);

/**
 *	Получает md5 hash файла.
 * @param sFile					Путь к файлу.
 * @param sBuffer				Строка куда будет записан hash.
 * @param len					Длина строки.
 *	-
 * @return	Возвращает true в случаи успеха.
 *	-
 * @error sFile не существует.
*/
native bool PTaH_MD5File(const char[] sFile, char[] sBuffer, int len);

/**
 *	Получает ip хоста.
 * @param sHostName					домен.
 *	-
 * @return	ip.
 *	-
 * @error -.
*/
native int PTaH_GetHostByName(const char[] sHostName);

public Extension __ext_PTaH = 
{
	name = "PTaH",
	file = "PTaH.ext",
#if defined AUTOLOAD_EXTENSIONS
	autoload = 1,
#else
	autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
	required = 1,
#else
	required = 0,
#endif
};

#if !defined REQUIRE_EXTENSIONS
public __ext_PTaH_SetNTVOptional()
{
	MarkNativeAsOptional("PTaH");
	MarkNativeAsOptional("PTaH_GetItemDefinitionByName");
	MarkNativeAsOptional("CEconItemDefinition.GetDefinitionIndex");
	MarkNativeAsOptional("CEconItemDefinition.GetLoadoutSlot");
	MarkNativeAsOptional("CEconItemDefinition.GetNumSupportedStickerSlots");
	MarkNativeAsOptional("PTaH_GetItemInLoadout");
	MarkNativeAsOptional("PTaH_GetEconItemViewFromWeapon");
	MarkNativeAsOptional("CEconItemView.GetCustomPaintKitIndex");
	MarkNativeAsOptional("CEconItemView.GetCustomPaintKitSeed");
	MarkNativeAsOptional("CEconItemView.GetCustomPaintKitWear");
	MarkNativeAsOptional("CEconItemView.GetStickerAttributeBySlotIndex");
	MarkNativeAsOptional("CEconItemView.IsTradable");
	MarkNativeAsOptional("CEconItemView.IsMarketable");	
	MarkNativeAsOptional("CEconItemView.GetItemDefinition");
	MarkNativeAsOptional("CEconItemView.GetAccountID");
	MarkNativeAsOptional("CEconItemView.GetQuality");
	MarkNativeAsOptional("CEconItemView.GetRarity");
	MarkNativeAsOptional("CEconItemView.GetFlags");
	MarkNativeAsOptional("CEconItemView.GetOrigin");
	MarkNativeAsOptional("CEconItemView.GetCustomName");
	MarkNativeAsOptional("CEconItemView.GetStatTrakKill");
	MarkNativeAsOptional("PTaH_GivePlayerItem");
	MarkNativeAsOptional("PTaH_MD5File");
	MarkNativeAsOptional("PTaH_GetHostByName");
}
#endif