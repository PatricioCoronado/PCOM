#include <windows.h>
#include <setupapi.h>
#include <ansi_c.h>
#include "LocateCOMCVI.h"

// NOTE: ASSUMES malloc() ALWAYS WORKS!

static HDEVINFO  BeginEnumeratePorts(VOID)
{
  BOOL guidTest=FALSE;
  DWORD RequiredSize=0;
  HDEVINFO DeviceInfoSet;
  char* buf;

        guidTest=SetupDiClassGuidsFromNameA(
        "Ports",0,0,&RequiredSize);
        if(RequiredSize < 1)return INVALID_HANDLE_VALUE;

        buf= malloc(RequiredSize*sizeof(GUID));

        guidTest=SetupDiClassGuidsFromNameA(
        "Ports",(GUID *)buf,RequiredSize*sizeof(GUID),&RequiredSize);

        if(!guidTest)return (HANDLE)-1;


           DeviceInfoSet=SetupDiGetClassDevs(
             (GUID *)buf,NULL,NULL,DIGCF_PRESENT);
             if(DeviceInfoSet == INVALID_HANDLE_VALUE)return INVALID_HANDLE_VALUE;

           free(buf);

return DeviceInfoSet;
}


int LocateCom(char *inval, int *list, int maxnum)
{
	DWORD i;
	SP_DEVINFO_DATA DeviceInfoData={0};
	int portsfound = 0;


	HDEVINFO hDevInfo = BeginEnumeratePorts();

	if (INVALID_HANDLE_VALUE==hDevInfo)
	{
		return 0;
	}


  // Enumerate through all devices in Set.
    
    DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
    for (i=0;SetupDiEnumDeviceInfo(hDevInfo,i,
        &DeviceInfoData);i++)
    {
        DWORD DataT;
        LPTSTR buffer = NULL;
        DWORD buffersize = 0;
        
        // 
        // Call function with null to begin with, 
        // then use the returned buffer size 
        // to Alloc the buffer. Keep calling until
        // success or an unknown failure.
        // 
        while (!SetupDiGetDeviceRegistryProperty(
            hDevInfo,
            &DeviceInfoData,
            SPDRP_FRIENDLYNAME,
            &DataT,
            (PBYTE)buffer,
            buffersize,
            &buffersize))
        {
            if (GetLastError() == 
                ERROR_INSUFFICIENT_BUFFER)
            {
                // Change the buffer size.
                if (buffer) free(buffer);
                buffer = malloc(buffersize);
            }
            else
            {
		        if (buffer) free(buffer);
                SetupDiDestroyDeviceInfoList(hDevInfo);
				return 0;
            }
        }

		if (NULL==buffer)
		{
			if (buffersize>0)
			{
				buffer = malloc(buffersize);
				SetupDiGetDeviceRegistryProperty(
					hDevInfo,
					&DeviceInfoData,
					SPDRP_FRIENDLYNAME,
					&DataT,
					(PBYTE)buffer,
					buffersize,
					&buffersize);
			}
		}
        
		// We may have found the device
		if ((NULL!=buffer) && strstr(buffer,inval))
		{
			char *xval;
			if (xval=strstr(buffer,"COM"))
			{
				int d;
				if ((1==sscanf(xval,"COM%d",&d)) && (d>=1) && (d<=255))
				{
					if ((NULL==list)||(maxnum<=0))
					{
						free(buffer);
						SetupDiDestroyDeviceInfoList(hDevInfo);
						return d;
					}
					else
					{
						if (portsfound<maxnum)
						{
							list[portsfound++] = d;
						}
					}
				}
			}
		}
 
		if (buffer) free(buffer);
    }

    
	SetupDiDestroyDeviceInfoList(hDevInfo);

	return portsfound;
}

