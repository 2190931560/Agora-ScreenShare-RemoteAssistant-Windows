#include "stdafx.h"
#include "RemoteAssistantTransfer.h"
using namespace AgoraRemoteTransfer;
#include "AgoraSignalWrapper.h"

CAgoraRemoteTransfer::CAgoraRemoteTransfer():
m_pSignalWrapper(nullptr),
m_strCommUID("")
{
	m_pSignalWrapper = CAgoraSignalWrapper::getInstance();
}

CAgoraRemoteTransfer::CAgoraRemoteTransfer(const std::string &strUID):
m_pSignalWrapper(nullptr),
m_strCommUID(strUID)
{
	m_pSignalWrapper = CAgoraSignalWrapper::getInstance();
}

CAgoraRemoteTransfer::~CAgoraRemoteTransfer()
{
	m_pSignalWrapper = nullptr;
}

void CAgoraRemoteTransfer::setRemoteUID(const std::string &strUID)
{
	m_strCommUID = strUID;
}

void CAgoraRemoteTransfer::start()
{
	OutputDebugString(_T(__FUNCTION__));
	OutputDebugString(_T("\n"));

	CJsonObject object;
	object.Add("nCmdType", eTransfer_StartAssistant);
	SYSTEMTIME st;
	GetSystemTime(&st);
	int lTimeStamp = (st.wHour * 3600 + st.wMinute * 60 + st.wSecond) * 1000 + st.wMilliseconds;
	object.Add("nTimeStamp", lTimeStamp);
	object.AddEmptySubObject("EventParam");

	std::string str = object.ToString();

	if (m_pSignalWrapper)
		m_pSignalWrapper->sendInstantMsg(m_strCommUID, str);
}

void CAgoraRemoteTransfer::stop()
{
	OutputDebugString(_T(__FUNCTION__));
	OutputDebugString(_T("\n"));

	CJsonObject object;
	object.Add("nCmdType", eTransfer_StopAssistant);
	SYSTEMTIME st;
	GetSystemTime(&st);
	long lTimeStamp = (st.wHour * 3600 + st.wMinute * 60 + st.wSecond) * 1000 + st.wMilliseconds;
	object.Add("nTimeStamp", lTimeStamp);
	object.AddEmptySubObject("EventParam");

	std::string str = object.ToString();

	if (m_pSignalWrapper)
		m_pSignalWrapper->sendInstantMsg(m_strCommUID, str);
}

void CAgoraRemoteTransfer::mouse_LBtnDown(WPARAM wParam,POINT pt)
{
	OutputDebugString(_T(__FUNCTION__));
	OutputDebugString(_T("\n"));

	CJsonObject object;
	object.Add("nCmdType", eTransfer_Mouse_LBtnDown);
	SYSTEMTIME st;
	GetSystemTime(&st);
	long lTimeStamp = (st.wHour * 3600 + st.wMinute * 60 + st.wSecond) * 1000 + st.wMilliseconds;
	object.Add("nTimeStamp", lTimeStamp);
	object.AddEmptySubObject("EventParam");
	object["EventParam"].AddEmptySubObject("point");
	object["EventParam"]["point"].Add("xPos", pt.x);
	object["EventParam"]["point"].Add("yPos", pt.y);

	std::string str = object.ToString();
	if (m_pSignalWrapper)
		m_pSignalWrapper->sendInstantMsg(m_strCommUID, str);
}

void CAgoraRemoteTransfer::mouse_LBtnUp(WPARAM wParam,POINT pt)
{
	OutputDebugString(_T(__FUNCTION__));
	OutputDebugString(_T("\n"));

	CJsonObject object;
	object.Add("nCmdType", eTransfer_Mouse_LBtnUp);
	SYSTEMTIME st;
	GetSystemTime(&st);
	long lTimeStamp = (st.wHour * 3600 + st.wMinute * 60 + st.wSecond) * 1000 + st.wMilliseconds;
	object.Add("nTimeStamp", lTimeStamp);
	object.AddEmptySubObject("EventParam");
	object["EventParam"].AddEmptySubObject("point");
	object["EventParam"]["point"].Add("xPos", pt.x);
	object["EventParam"]["point"].Add("yPos", pt.y);

	std::string str = object.ToString();
	if (m_pSignalWrapper)
		m_pSignalWrapper->sendInstantMsg(m_strCommUID, str);
}

void CAgoraRemoteTransfer::mouse_LBtnDClick(WPARAM wParam,POINT pt)
{
	OutputDebugString(_T(__FUNCTION__));
	OutputDebugString(_T("\n"));

	CJsonObject object;
	object.Add("nCmdType", eTransfer_Mouse_LBtnDClick);
	SYSTEMTIME st;
	GetSystemTime(&st);
	long lTimeStamp = (st.wHour * 3600 + st.wMinute * 60 + st.wSecond) * 1000 + st.wMilliseconds;
	object.Add("nTimeStamp", lTimeStamp);
	object.AddEmptySubObject("EventParam");
	object["EventParam"].AddEmptySubObject("point");
	object["EventParam"]["point"].Add("xPos", pt.x);
	object["EventParam"]["point"].Add("yPos", pt.y);

	std::string str = object.ToString();
	if (m_pSignalWrapper)
		m_pSignalWrapper->sendInstantMsg(m_strCommUID, str);
}

void CAgoraRemoteTransfer::mouse_RBtnDown(WPARAM wParam,POINT pt)
{
	OutputDebugString(_T(__FUNCTION__));
	OutputDebugString(_T("\n"));

	CJsonObject object;
	object.Add("nCmdType", eTransfer_Mouse_RBtnDown);
	SYSTEMTIME st;
	GetSystemTime(&st);
	long lTimeStamp = (st.wHour * 3600 + st.wMinute * 60 + st.wSecond) * 1000 + st.wMilliseconds;
	object.Add("nTimeStamp", lTimeStamp);
	object.AddEmptySubObject("EventParam");
	object["EventParam"].AddEmptySubObject("point");
	object["EventParam"]["point"].Add("xPos", pt.x);
	object["EventParam"]["point"].Add("yPos", pt.y);

	std::string str = object.ToString();
	if (m_pSignalWrapper)
		m_pSignalWrapper->sendInstantMsg(m_strCommUID, str);
}

void CAgoraRemoteTransfer::mouse_RBtnUp(WPARAM wParam,POINT pt)
{
	OutputDebugString(_T(__FUNCTION__));
	OutputDebugString(_T("\n"));

	CJsonObject object;
	object.Add("nCmdType", eTransfer_Mouse_RBtnUp);
	SYSTEMTIME st;
	GetSystemTime(&st);
	long lTimeStamp = (st.wHour * 3600 + st.wMinute * 60 + st.wSecond) * 1000 + st.wMilliseconds;
	object.Add("nTimeStamp", lTimeStamp);
	object.AddEmptySubObject("EventParam");
	object["EventParam"].AddEmptySubObject("point");
	object["EventParam"]["point"].Add("xPos", pt.x);
	object["EventParam"]["point"].Add("yPos", pt.y);

	std::string str = object.ToString();
	if (m_pSignalWrapper)
		m_pSignalWrapper->sendInstantMsg(m_strCommUID, str);
}

void CAgoraRemoteTransfer::mouse_RBtnDClick(WPARAM wParam,POINT pt)
{
	OutputDebugString(_T(__FUNCTION__));
	OutputDebugString(_T("\n"));

	CJsonObject object;
	object.Add("nCmdType", eTransfer_Mouse_RBtnDClick);
	SYSTEMTIME st;
	GetSystemTime(&st);
	long lTimeStamp = (st.wHour * 3600 + st.wMinute * 60 + st.wSecond) * 1000 + st.wMilliseconds;
	object.Add("nTimeStamp", lTimeStamp);
	object.AddEmptySubObject("EventParam");
	object["EventParam"].AddEmptySubObject("point");
	object["EventParam"]["point"].Add("xPos", pt.x);
	object["EventParam"]["point"].Add("yPos", pt.y);

	std::string str = object.ToString();
	if (m_pSignalWrapper)
		m_pSignalWrapper->sendInstantMsg(m_strCommUID, str);
}

void CAgoraRemoteTransfer::mouse_Move(WPARAM wParam,POINT pt)
{
	OutputDebugString(_T(__FUNCTION__));
	OutputDebugString(_T("\n"));

	static POINT spt;
	if (spt.x != pt.x && spt.y != pt.y) {
		spt.x = pt.x;
		spt.y = pt.y;
	}
	else
		return;

	CJsonObject object;
	object.Add("nCmdType", eTransfer_Mouse_Move);
	SYSTEMTIME st;
	GetSystemTime(&st);
	long lTimeStamp = (st.wHour * 3600 + st.wMinute * 60 + st.wSecond) * 1000 + st.wMilliseconds;
	object.Add("nTimeStamp", lTimeStamp);
	object.AddEmptySubObject("EventParam");
	object["EventParam"].AddEmptySubObject("point");
	object["EventParam"]["point"].Add("xPos", pt.x);
	object["EventParam"]["point"].Add("yPos", pt.y);

	std::string str = object.ToString();
	if (m_pSignalWrapper)
		m_pSignalWrapper->sendInstantMsg(m_strCommUID, str);
}

void CAgoraRemoteTransfer::mouse_Wheel(WPARAM wParam, POINT pt)
{
	OutputDebugString(_T(__FUNCTION__));
	OutputDebugString(_T("\n"));

	CJsonObject object;
	object.Add("nCmdType", eTransfer_Mouse_Wheel);
	SYSTEMTIME st;
	GetSystemTime(&st);
	long lTimeStamp = (st.wHour * 3600 + st.wMinute * 60 + st.wSecond) * 1000 + st.wMilliseconds;
	object.Add("nTimeStamp", lTimeStamp);
	object.AddEmptySubObject("EventParam");
	object["EventParam"].AddEmptySubObject("point");
	object["EventParam"]["point"].Add("xPos", pt.x);
	object["EventParam"]["point"].Add("yPos", pt.y);
	object["EventParam"].Add("wParam", wParam);

	std::string str = object.ToString();
	if (m_pSignalWrapper)
		m_pSignalWrapper->sendInstantMsg(m_strCommUID, str);
}

void CAgoraRemoteTransfer::keyboard_charnum(WPARAM wParam,int nNum)
{
	OutputDebugString(_T(__FUNCTION__));
	OutputDebugString(_T("\n"));

	CJsonObject object;
	object.Add("nCmdType", eTransfer_KeyBoard_CharNum);
	SYSTEMTIME st;
	GetSystemTime(&st);
	long lTimeStamp = (st.wHour * 3600 + st.wMinute * 60 + st.wSecond) * 1000 + st.wMilliseconds;
	object.Add("nTimeStamp", lTimeStamp);
	object.AddEmptySubObject("EventParam");
	object["EventParam"].Add("input", nNum);
	object["EventParam"].Add("wParam", wParam);

	std::string str = object.ToString();
	if (m_pSignalWrapper)
		m_pSignalWrapper->sendInstantMsg(m_strCommUID, str);
}

void CAgoraRemoteTransfer::keyboard_copy(const std::string &copycontext)
{
	OutputDebugString(_T(__FUNCTION__));
	OutputDebugString(_T("\n"));

	CJsonObject object;
	object.Add("nCmdType", eTransfer_KeyBoard_Copy);
	SYSTEMTIME st;
	GetSystemTime(&st);
	long lTimeStamp = (st.wHour * 3600 + st.wMinute * 60 + st.wSecond) * 1000 + st.wMilliseconds;
	object.Add("nTimeStamp", lTimeStamp);
	object.AddEmptySubObject("EventParam");
	object["EventParam"].Add("copyContent", copycontext);

	std::string str = object.ToString();
	if (m_pSignalWrapper)
		m_pSignalWrapper->sendInstantMsg(m_strCommUID, str);
}

void CAgoraRemoteTransfer::keyboard_paste(const std::string &pastecontext)
{
	OutputDebugString(_T(__FUNCTION__));
	OutputDebugString(_T("\n"));

	CJsonObject object;
	object.Add("nCmdType", eTransfer_KeyBoard_Paste);
	SYSTEMTIME st;
	GetSystemTime(&st);
	long lTimeStamp = (st.wHour * 3600 + st.wMinute * 60 + st.wSecond) * 1000 + st.wMilliseconds;
	object.Add("nTimeStamp", lTimeStamp);
	object.AddEmptySubObject("EventParam");
	object["EventParam"].Add("pasteContent", pastecontext);

	std::string str = object.ToString();
	if (m_pSignalWrapper)
		m_pSignalWrapper->sendInstantMsg(m_strCommUID, str);
}
