
#include "FileSync.h"
#include <string>
#include <locale>
#include <codecvt>
#include <sstream>

const std::wstring ProudChat::CFileSync::GetCDNFile(const std::wstring& cdnUrl, const std::wstring& saveFilePath)
{
	// curl�� ����Ͽ� ���� �ٿ�ε�
	std::wstring downloadCommand = L"curl -o " + saveFilePath + L" " + cdnUrl;
	int downloadResult = _wsystem(downloadCommand.c_str());

	if (downloadResult == 0) {
		std::wcout << L"���� �ٿ�ε� ����!" << std::endl;

		// �ٿ�ε�� ������ ����
		std::wifstream file(saveFilePath);
		if (file.is_open()) {
			file.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
			std::wstringstream wss;
			wss << file.rdbuf();
			return wss.str();
		}
		else {
			std::wcerr << L"������ ���� �� �����ϴ�." << std::endl;
		}
	}
	else {
		std::wcerr << L"���� �ٿ�ε� ����!" << std::endl;
	}
	return L"";
}
