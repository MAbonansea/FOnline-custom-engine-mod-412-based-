//////////////////////////////////////////////////////////////////////
// CPro Class
//////////////////////////////////////////////////////////////////////

#include "pro.h"
#include "mdi.h"
#include "utilites.h"

//---------------------------------------------------------------------------
CPro::CPro(void)
{
   data         = NULL;
   FileName     = NULL;
}
//---------------------------------------------------------------------------
void CPro::LoadData(DWORD size)
{
    // ����� ��������� ������
    if ((data = (BYTE *)malloc(size)) == NULL) return;
}
//---------------------------------------------------------------------------
DWORD CPro::GetMsgID(void)
{
    // ������������� �������� �������
    return pUtil->GetDW((DWORD *)&data[0x04]);
}
//---------------------------------------------------------------------------
DWORD CPro::GetFrmIDDW(void)
{
    // ������������� �����������
    return pUtil->GetDW((DWORD *)&data[0x08]);
}
//---------------------------------------------------------------------------
WORD CPro::GetFrmID(void)
{
    //
    return pUtil->GetW((WORD *)&data[0x0a]);
}
//---------------------------------------------------------------------------
WORD CPro::GetInvFrmID(void)
{
   return pUtil->GetW((WORD *)&data[0x36]);
}
//---------------------------------------------------------------------------
DWORD CPro::GetSubType(void)
{
   return pUtil->GetDW((DWORD *)&data[0x20]);
}
//---------------------------------------------------------------------------
DWORD CPro::GetFlags(void)
{
   return pUtil->GetDW((DWORD *)&data[0x14]);
}
//---------------------------------------------------------------------------
CPro::~CPro()
{
   if (data != NULL) free(data);
}
//---------------------------------------------------------------------------

