
HRSRC hRsrc = FindResource(0, (LPCWSTR)101, L"MYDLL");

DWORD dwSize = SizeofResource(NULL, hRsrc);

HGLOBAL hGlobal = LoadResource(NULL, hRsrc);

LPVOID lpVoid = LockResource(hGlobal);

FILE* fp = NULL;
fopen_s(&fp, "common.dll", "wb+");
fwrite(lpVoid, sizeof(char), dwSize, fp);
fclose(fp);