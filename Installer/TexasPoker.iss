; Texas Poker Installer

#define MyAppName "Texas Poker"
#define MyAppVersion "1.0"
#define MyAppPublisher "Irmuun Naranbaatar"
#define MyAppURL "https://yourname.itch.io/texas-poker"
#define MyAppExeName "poker.exe"

[Setup]
AppId={{7F1D6F54-B427-482A-BCEB-139D3A5DD7D6}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={autopf}\{#MyAppName}
DefaultGroupName={#MyAppName}
UninstallDisplayIcon={app}\{#MyAppExeName}
ArchitecturesAllowed=x64compatible
ArchitecturesInstallIn64BitMode=x64compatible
DisableProgramGroupPage=yes
OutputBaseFilename=TexasPokerSetup
Compression=lzma2
SolidCompression=yes
WizardStyle=modern
OutputDir=D:\Coding\casino\Texas poker\Installer

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"

[Files]
Source: "D:\Coding\casino\Texas poker\poker.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Coding\casino\Texas poker\*.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "D:\Coding\casino\Texas poker\Assets\*"; DestDir: "{app}\Assets"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
Name: "{autoprograms}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "Launch Texas Poker"; Flags: nowait postinstall skipifsilent