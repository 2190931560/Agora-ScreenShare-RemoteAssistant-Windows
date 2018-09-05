// RemoteAssistantDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ScreenShare-RemoteAssistant.h"
#include "RemoteAssistantDlg.h"
#include "afxdialogex.h"
#include "AgoraConfig.h"
#include "AgoraMediaWrapper.h"
#include "AgoraSignalWrapper.h"


// CRemoteAssistantDlg dialog

IMPLEMENT_DYNAMIC(CRemoteAssistantDlg, CDialogEx)

CRemoteAssistantDlg::CRemoteAssistantDlg(UINT uID,CWnd* pParent /*=NULL*/)
	: CDialogEx(CRemoteAssistantDlg::IDD, pParent),
	m_nScreenH(0),
	m_nScreenW(0),
	m_pMediaWrapper(nullptr),
	m_uRemoteID(uID)
{

}

CRemoteAssistantDlg::~CRemoteAssistantDlg()
{
}

void CRemoteAssistantDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRemoteAssistantDlg, CDialogEx)
	ON_WM_PAINT()
	ON_MESSAGE(WM_LoginSuccess,onLoginSuccess)
	ON_MESSAGE(WM_LoginFailed,onLogFailed)
	ON_MESSAGE(WM_LogOut,onLogout)
	ON_MESSAGE(WM_Error,onError)
	ON_MESSAGE(WM_Log,onLog)
	ON_MESSAGE(WM_QueryUserStatusResult,onQueryUserStatusResult)
	ON_MESSAGE(WM_MessageSendSuccess,onMessageSendSuccess)
	ON_MESSAGE(WM_MessageSendError,onMessageSendError)
	ON_MESSAGE(WM_MessageInstantReceive,onMessageInstantReceive)
	ON_MESSAGE(WM_MessageChannelReceive,onMessageChannelReceive)
	ON_MESSAGE(WM_ChannelJoined,onChannelJoined)
	ON_MESSAGE(WM_ChannelJoinedFailed,onChannelJoinFailed)
	ON_MESSAGE(WM_ChannelLeaved,onChannelLeaved)
END_MESSAGE_MAP()


// CRemoteAssistantDlg message handlers
BOOL CRemoteAssistantDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_nScreenW = GetSystemMetrics(SM_CXSCREEN);
	m_nScreenH = GetSystemMetrics(SM_CYSCREEN);

	//MoveWindow(0, 0, m_nScreenW, m_nScreenH);
	m_penFrame.CreatePen(PS_SOLID, 4, RGB(0x00, 0xA0, 0xE9));

	m_pMediaWrapper = CAgoraMediaWrapper::getInstance();
	if (m_pMediaWrapper) {
		m_pMediaWrapper->setRemoteVideo(m_hWnd, m_uRemoteID);
	}
	
	m_pSignalWrapper = CAgoraSignalWrapper::getInstance();

	return TRUE;
}

void CRemoteAssistantDlg::initCtrl()
{

}

void CRemoteAssistantDlg::initSignalResource()
{
}

void CRemoteAssistantDlg::uninitResource()
{
}

int CRemoteAssistantDlg::PreTranslateMessage(MSG* pMsg)
{
	//���: �������,���˫��,�Ҽ�����,�Ҽ�˫��,�϶�.
	//����:����,��ĸ.
	//��ݼ�:ctrl+c,ctrl+v

	if (pMsg->hwnd == m_hWnd) {

		switch (pMsg->message)
		{
		case WM_LBUTTONDBLCLK:break;
		case WM_LBUTTONDOWN:break;
		case WM_LBUTTONUP:break;
		case WM_RBUTTONDBLCLK:break;
		case WM_RBUTTONUP: break;
		case WM_RBUTTONDOWN:break;
		case WM_CHAR:break;
		}
	}
	
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CRemoteAssistantDlg::OnPaint()
{
	CPaintDC dc(this);
	CDC dcMem;
	CBitmap bmpBuffer;

	CRect rt;
	GetClientRect(&rt);

	dcMem.CreateCompatibleDC(&dc);
	bmpBuffer.CreateCompatibleBitmap(&dc, rt.Width(), rt.Height());

	CBitmap *lpOldBitmap = dcMem.SelectObject(&bmpBuffer);
	CPen* defPen = dcMem.SelectObject(&m_penFrame);
	dcMem.Rectangle(rt);
	::BitBlt(dc, 0, 0, rt.right, rt.bottom, dcMem, 0, 0, SRCCOPY);

	//dc.SelectObject(defPen);
}

HRESULT CRemoteAssistantDlg::onLoginSuccess(WPARAM wParam, LPARAM lParam)
{
	PAG_SIGNAL_LOGINSUCCESS lpData = (PAG_SIGNAL_LOGINSUCCESS)wParam;
	if (lpData) {

		delete lpData; lpData = nullptr;
	}

	return TRUE;
}

HRESULT CRemoteAssistantDlg::onLogout(WPARAM wParam, LPARAM lParam)
{
	PAG_SIGNAL_LOGOUT lpData = (PAG_SIGNAL_LOGOUT)wParam;
	if (lpData) {

		delete lpData; lpData = nullptr;
	}
	return TRUE;
}

HRESULT CRemoteAssistantDlg::onLogFailed(WPARAM wParam, LPARAM lParam)
{
	PAG_SIGNAL_LOGINFAILED lpData = (PAG_SIGNAL_LOGINFAILED)wParam;
	if (lpData) {
		delete lpData; lpData = nullptr;
	}

	return TRUE;
}

LRESULT CRemoteAssistantDlg::onError(WPARAM wParam, LPARAM lParam)
{
	PAG_SIGNAL_CHANNELJOIN lpData = (PAG_SIGNAL_CHANNELJOIN)wParam;
	if (lpData) {
		delete lpData; lpData = nullptr;
	}
	return TRUE;
}

LRESULT CRemoteAssistantDlg::onLog(WPARAM wParam, LPARAM lParam)
{
	PAG_SIGNAL_LOG lpData = (PAG_SIGNAL_LOG)wParam;
	if (lpData) {
		delete lpData; lpData = nullptr;
	}

	return TRUE;
}

HRESULT CRemoteAssistantDlg::onQueryUserStatusResult(WPARAM wParam, LPARAM lParam)
{
	PAG_SIGNAL_QUERYUSERSTATUSRESULT lpData = (PAG_SIGNAL_QUERYUSERSTATUSRESULT)wParam;
	if (lpData) {
		delete lpData; lpData = nullptr;
	}

	return TRUE;
}

HRESULT CRemoteAssistantDlg::onMessageSendSuccess(WPARAM wParam, LPARAM lParam)
{
	PAG_SIGNAL_MESSAGESENDSUCCESS lpData = (PAG_SIGNAL_MESSAGESENDSUCCESS)wParam;
	if (lpData) {
		delete lpData; lpData = nullptr;
	}

	return TRUE;
}

HRESULT CRemoteAssistantDlg::onMessageSendError(WPARAM wParam, LPARAM lParam)
{
	PAG_SIGNAL_MESSAGESENDERROR lpData = (PAG_SIGNAL_MESSAGESENDERROR)wParam;
	if (lpData) {
		delete lpData; lpData = nullptr;
	}

	return TRUE;
}

HRESULT CRemoteAssistantDlg::onMessageInstantReceive(WPARAM wParam, LPARAM lParam)
{
	PAG_SIGNAL_MESSAGEINSTANCERECEIVE lpData = (PAG_SIGNAL_MESSAGEINSTANCERECEIVE)wParam;
	if (lpData) {
		delete lpData; lpData = nullptr;
	}
	return TRUE;
}

HRESULT CRemoteAssistantDlg::onMessageChannelReceive(WPARAM wParam, LPARAM lParam)
{
	PAG_SIGNAL_MESSAGECHANNELRECEIVE lpData = (PAG_SIGNAL_MESSAGECHANNELRECEIVE)wParam;
	if (lpData) {
		delete lpData; lpData = nullptr;
	}

	return TRUE;
}

HRESULT CRemoteAssistantDlg::onChannelJoined(WPARAM wParam, LPARAM lParam)
{
	PAG_SIGNAL_CHANNELJOIN lpData = (PAG_SIGNAL_CHANNELJOIN)wParam;
	if (lpData) {
		delete lpData; lpData = nullptr;
	}
	return TRUE;
}

HRESULT CRemoteAssistantDlg::onChannelJoinFailed(WPARAM wParam, LPARAM lParam)
{
	PAG_SIGNAL_CHANNELJOINFAILED lpData = (PAG_SIGNAL_CHANNELJOINFAILED)wParam;
	if (lpData) {
		delete lpData; lpData = nullptr;
	}

	return TRUE;
}

HRESULT CRemoteAssistantDlg::onChannelLeaved(WPARAM wParam, LPARAM lParam)
{
	PAG_SIGNAL_CHANNELLEAVE lpData = (PAG_SIGNAL_CHANNELLEAVE)wParam;
	if (lpData) {
		delete lpData; lpData = nullptr;
	}
	return TRUE;
}