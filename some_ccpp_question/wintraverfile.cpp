#include <Windows.h>
#include <ShlObj.h>
typedef void(*pVisitFile)(LPWSTR lpPath);

void TraverFolder(pVisitFile visit, LPWSTR lpPath)
{
	WCHAR save_path[200];
	WCHAR szFile[MAX_PATH] = { 0 };
	WCHAR szFind[MAX_PATH];
	WCHAR root[MAX_PATH];

	WIN32_FIND_DATA FindFileData;
	lstrcpy(szFind, lpPath);

	lstrcat(szFind, L"\\*.*");
	HANDLE hFind = ::FindFirstFile(szFind, &FindFileData);

	if (INVALID_HANDLE_VALUE == hFind) return;
	while (TRUE)
	{
		if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if (FindFileData.cFileName[0] != '.')
			{
				lstrcpy(szFile, lpPath);
				lstrcat(szFile, L"\\");
				lstrcat(szFile, FindFileData.cFileName);
				TraverFolder(visit, szFile);
			}
		}
		else
		{
			lstrcpy(szFile, lpPath);
			lstrcat(szFile, L"\\");
			lstrcat(szFile, FindFileData.cFileName);
			visit(szFile);
		}

		if (!FindNextFile(hFind, &FindFileData))
		{
			break;
		}
	}
	FindClose(hFind);
}
