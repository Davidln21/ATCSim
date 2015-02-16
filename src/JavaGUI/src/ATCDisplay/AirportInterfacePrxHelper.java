// **********************************************************************
//
// Copyright (c) 2003-2011 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.4.2
//
// <auto-generated>
//
// Generated from file `AirportInterfacePrxHelper.java'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

package ATCDisplay;

public final class AirportInterfacePrxHelper extends Ice.ObjectPrxHelperBase implements AirportInterfacePrx
{
    public void
    UpdateSimT(float inc)
    {
        UpdateSimT(inc, null, false);
    }

    public void
    UpdateSimT(float inc, java.util.Map<String, String> __ctx)
    {
        UpdateSimT(inc, __ctx, true);
    }

    private void
    UpdateSimT(float inc, java.util.Map<String, String> __ctx, boolean __explicitCtx)
    {
        if(__explicitCtx && __ctx == null)
        {
            __ctx = _emptyContext;
        }
        int __cnt = 0;
        while(true)
        {
            Ice._ObjectDel __delBase = null;
            try
            {
                __delBase = __getDelegate(false);
                _AirportInterfaceDel __del = (_AirportInterfaceDel)__delBase;
                __del.UpdateSimT(inc, __ctx);
                return;
            }
            catch(IceInternal.LocalExceptionWrapper __ex)
            {
                __handleExceptionWrapper(__delBase, __ex);
            }
            catch(Ice.LocalException __ex)
            {
                __cnt = __handleException(__delBase, __ex, null, __cnt);
            }
        }
    }

    private static final String __UpdateSimT_name = "UpdateSimT";

    public Ice.AsyncResult begin_UpdateSimT(float inc)
    {
        return begin_UpdateSimT(inc, null, false, null);
    }

    public Ice.AsyncResult begin_UpdateSimT(float inc, java.util.Map<String, String> __ctx)
    {
        return begin_UpdateSimT(inc, __ctx, true, null);
    }

    public Ice.AsyncResult begin_UpdateSimT(float inc, Ice.Callback __cb)
    {
        return begin_UpdateSimT(inc, null, false, __cb);
    }

    public Ice.AsyncResult begin_UpdateSimT(float inc, java.util.Map<String, String> __ctx, Ice.Callback __cb)
    {
        return begin_UpdateSimT(inc, __ctx, true, __cb);
    }

    public Ice.AsyncResult begin_UpdateSimT(float inc, Callback_AirportInterface_UpdateSimT __cb)
    {
        return begin_UpdateSimT(inc, null, false, __cb);
    }

    public Ice.AsyncResult begin_UpdateSimT(float inc, java.util.Map<String, String> __ctx, Callback_AirportInterface_UpdateSimT __cb)
    {
        return begin_UpdateSimT(inc, __ctx, true, __cb);
    }

    private Ice.AsyncResult begin_UpdateSimT(float inc, java.util.Map<String, String> __ctx, boolean __explicitCtx, IceInternal.CallbackBase __cb)
    {
        IceInternal.OutgoingAsync __result = new IceInternal.OutgoingAsync(this, __UpdateSimT_name, __cb);
        try
        {
            __result.__prepare(__UpdateSimT_name, Ice.OperationMode.Normal, __ctx, __explicitCtx);
            IceInternal.BasicStream __os = __result.__os();
            __os.writeFloat(inc);
            __os.endWriteEncaps();
            __result.__send(true);
        }
        catch(Ice.LocalException __ex)
        {
            __result.__exceptionAsync(__ex);
        }
        return __result;
    }

    public void end_UpdateSimT(Ice.AsyncResult __result)
    {
        __end(__result, __UpdateSimT_name);
    }

    public ATCDAirport
    getAirportInfo()
    {
        return getAirportInfo(null, false);
    }

    public ATCDAirport
    getAirportInfo(java.util.Map<String, String> __ctx)
    {
        return getAirportInfo(__ctx, true);
    }

    private ATCDAirport
    getAirportInfo(java.util.Map<String, String> __ctx, boolean __explicitCtx)
    {
        if(__explicitCtx && __ctx == null)
        {
            __ctx = _emptyContext;
        }
        int __cnt = 0;
        while(true)
        {
            Ice._ObjectDel __delBase = null;
            try
            {
                __checkTwowayOnly("getAirportInfo");
                __delBase = __getDelegate(false);
                _AirportInterfaceDel __del = (_AirportInterfaceDel)__delBase;
                return __del.getAirportInfo(__ctx);
            }
            catch(IceInternal.LocalExceptionWrapper __ex)
            {
                __cnt = __handleExceptionWrapperRelaxed(__delBase, __ex, null, __cnt);
            }
            catch(Ice.LocalException __ex)
            {
                __cnt = __handleException(__delBase, __ex, null, __cnt);
            }
        }
    }

    private static final String __getAirportInfo_name = "getAirportInfo";

    public Ice.AsyncResult begin_getAirportInfo()
    {
        return begin_getAirportInfo(null, false, null);
    }

    public Ice.AsyncResult begin_getAirportInfo(java.util.Map<String, String> __ctx)
    {
        return begin_getAirportInfo(__ctx, true, null);
    }

    public Ice.AsyncResult begin_getAirportInfo(Ice.Callback __cb)
    {
        return begin_getAirportInfo(null, false, __cb);
    }

    public Ice.AsyncResult begin_getAirportInfo(java.util.Map<String, String> __ctx, Ice.Callback __cb)
    {
        return begin_getAirportInfo(__ctx, true, __cb);
    }

    public Ice.AsyncResult begin_getAirportInfo(Callback_AirportInterface_getAirportInfo __cb)
    {
        return begin_getAirportInfo(null, false, __cb);
    }

    public Ice.AsyncResult begin_getAirportInfo(java.util.Map<String, String> __ctx, Callback_AirportInterface_getAirportInfo __cb)
    {
        return begin_getAirportInfo(__ctx, true, __cb);
    }

    private Ice.AsyncResult begin_getAirportInfo(java.util.Map<String, String> __ctx, boolean __explicitCtx, IceInternal.CallbackBase __cb)
    {
        __checkAsyncTwowayOnly(__getAirportInfo_name);
        IceInternal.OutgoingAsync __result = new IceInternal.OutgoingAsync(this, __getAirportInfo_name, __cb);
        try
        {
            __result.__prepare(__getAirportInfo_name, Ice.OperationMode.Idempotent, __ctx, __explicitCtx);
            IceInternal.BasicStream __os = __result.__os();
            __os.endWriteEncaps();
            __result.__send(true);
        }
        catch(Ice.LocalException __ex)
        {
            __result.__exceptionAsync(__ex);
        }
        return __result;
    }

    public ATCDAirport end_getAirportInfo(Ice.AsyncResult __result)
    {
        Ice.AsyncResult.__check(__result, this, __getAirportInfo_name);
        if(!__result.__wait())
        {
            try
            {
                __result.__throwUserException();
            }
            catch(Ice.UserException __ex)
            {
                throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
            }
        }
        ATCDAirport __ret;
        IceInternal.BasicStream __is = __result.__is();
        __is.startReadEncaps();
        __ret = new ATCDAirport();
        __ret.__read(__is);
        __is.endReadEncaps();
        return __ret;
    }

    public java.util.List<ATCDFlight>
    getFlights()
    {
        return getFlights(null, false);
    }

    public java.util.List<ATCDFlight>
    getFlights(java.util.Map<String, String> __ctx)
    {
        return getFlights(__ctx, true);
    }

    private java.util.List<ATCDFlight>
    getFlights(java.util.Map<String, String> __ctx, boolean __explicitCtx)
    {
        if(__explicitCtx && __ctx == null)
        {
            __ctx = _emptyContext;
        }
        int __cnt = 0;
        while(true)
        {
            Ice._ObjectDel __delBase = null;
            try
            {
                __checkTwowayOnly("getFlights");
                __delBase = __getDelegate(false);
                _AirportInterfaceDel __del = (_AirportInterfaceDel)__delBase;
                return __del.getFlights(__ctx);
            }
            catch(IceInternal.LocalExceptionWrapper __ex)
            {
                __cnt = __handleExceptionWrapperRelaxed(__delBase, __ex, null, __cnt);
            }
            catch(Ice.LocalException __ex)
            {
                __cnt = __handleException(__delBase, __ex, null, __cnt);
            }
        }
    }

    private static final String __getFlights_name = "getFlights";

    public Ice.AsyncResult begin_getFlights()
    {
        return begin_getFlights(null, false, null);
    }

    public Ice.AsyncResult begin_getFlights(java.util.Map<String, String> __ctx)
    {
        return begin_getFlights(__ctx, true, null);
    }

    public Ice.AsyncResult begin_getFlights(Ice.Callback __cb)
    {
        return begin_getFlights(null, false, __cb);
    }

    public Ice.AsyncResult begin_getFlights(java.util.Map<String, String> __ctx, Ice.Callback __cb)
    {
        return begin_getFlights(__ctx, true, __cb);
    }

    public Ice.AsyncResult begin_getFlights(Callback_AirportInterface_getFlights __cb)
    {
        return begin_getFlights(null, false, __cb);
    }

    public Ice.AsyncResult begin_getFlights(java.util.Map<String, String> __ctx, Callback_AirportInterface_getFlights __cb)
    {
        return begin_getFlights(__ctx, true, __cb);
    }

    private Ice.AsyncResult begin_getFlights(java.util.Map<String, String> __ctx, boolean __explicitCtx, IceInternal.CallbackBase __cb)
    {
        __checkAsyncTwowayOnly(__getFlights_name);
        IceInternal.OutgoingAsync __result = new IceInternal.OutgoingAsync(this, __getFlights_name, __cb);
        try
        {
            __result.__prepare(__getFlights_name, Ice.OperationMode.Idempotent, __ctx, __explicitCtx);
            IceInternal.BasicStream __os = __result.__os();
            __os.endWriteEncaps();
            __result.__send(true);
        }
        catch(Ice.LocalException __ex)
        {
            __result.__exceptionAsync(__ex);
        }
        return __result;
    }

    public java.util.List<ATCDFlight> end_getFlights(Ice.AsyncResult __result)
    {
        Ice.AsyncResult.__check(__result, this, __getFlights_name);
        if(!__result.__wait())
        {
            try
            {
                __result.__throwUserException();
            }
            catch(Ice.UserException __ex)
            {
                throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
            }
        }
        java.util.List<ATCDFlight> __ret;
        IceInternal.BasicStream __is = __result.__is();
        __is.startReadEncaps();
        __ret = ATCDFlightsHelper.read(__is);
        __is.endReadEncaps();
        return __ret;
    }

    public int
    getMaxFlights()
    {
        return getMaxFlights(null, false);
    }

    public int
    getMaxFlights(java.util.Map<String, String> __ctx)
    {
        return getMaxFlights(__ctx, true);
    }

    private int
    getMaxFlights(java.util.Map<String, String> __ctx, boolean __explicitCtx)
    {
        if(__explicitCtx && __ctx == null)
        {
            __ctx = _emptyContext;
        }
        int __cnt = 0;
        while(true)
        {
            Ice._ObjectDel __delBase = null;
            try
            {
                __checkTwowayOnly("getMaxFlights");
                __delBase = __getDelegate(false);
                _AirportInterfaceDel __del = (_AirportInterfaceDel)__delBase;
                return __del.getMaxFlights(__ctx);
            }
            catch(IceInternal.LocalExceptionWrapper __ex)
            {
                __cnt = __handleExceptionWrapperRelaxed(__delBase, __ex, null, __cnt);
            }
            catch(Ice.LocalException __ex)
            {
                __cnt = __handleException(__delBase, __ex, null, __cnt);
            }
        }
    }

    private static final String __getMaxFlights_name = "getMaxFlights";

    public Ice.AsyncResult begin_getMaxFlights()
    {
        return begin_getMaxFlights(null, false, null);
    }

    public Ice.AsyncResult begin_getMaxFlights(java.util.Map<String, String> __ctx)
    {
        return begin_getMaxFlights(__ctx, true, null);
    }

    public Ice.AsyncResult begin_getMaxFlights(Ice.Callback __cb)
    {
        return begin_getMaxFlights(null, false, __cb);
    }

    public Ice.AsyncResult begin_getMaxFlights(java.util.Map<String, String> __ctx, Ice.Callback __cb)
    {
        return begin_getMaxFlights(__ctx, true, __cb);
    }

    public Ice.AsyncResult begin_getMaxFlights(Callback_AirportInterface_getMaxFlights __cb)
    {
        return begin_getMaxFlights(null, false, __cb);
    }

    public Ice.AsyncResult begin_getMaxFlights(java.util.Map<String, String> __ctx, Callback_AirportInterface_getMaxFlights __cb)
    {
        return begin_getMaxFlights(__ctx, true, __cb);
    }

    private Ice.AsyncResult begin_getMaxFlights(java.util.Map<String, String> __ctx, boolean __explicitCtx, IceInternal.CallbackBase __cb)
    {
        __checkAsyncTwowayOnly(__getMaxFlights_name);
        IceInternal.OutgoingAsync __result = new IceInternal.OutgoingAsync(this, __getMaxFlights_name, __cb);
        try
        {
            __result.__prepare(__getMaxFlights_name, Ice.OperationMode.Idempotent, __ctx, __explicitCtx);
            IceInternal.BasicStream __os = __result.__os();
            __os.endWriteEncaps();
            __result.__send(true);
        }
        catch(Ice.LocalException __ex)
        {
            __result.__exceptionAsync(__ex);
        }
        return __result;
    }

    public int end_getMaxFlights(Ice.AsyncResult __result)
    {
        Ice.AsyncResult.__check(__result, this, __getMaxFlights_name);
        if(!__result.__wait())
        {
            try
            {
                __result.__throwUserException();
            }
            catch(Ice.UserException __ex)
            {
                throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
            }
        }
        int __ret;
        IceInternal.BasicStream __is = __result.__is();
        __is.startReadEncaps();
        __ret = __is.readInt();
        __is.endReadEncaps();
        return __ret;
    }

    public int
    getPoints()
    {
        return getPoints(null, false);
    }

    public int
    getPoints(java.util.Map<String, String> __ctx)
    {
        return getPoints(__ctx, true);
    }

    private int
    getPoints(java.util.Map<String, String> __ctx, boolean __explicitCtx)
    {
        if(__explicitCtx && __ctx == null)
        {
            __ctx = _emptyContext;
        }
        int __cnt = 0;
        while(true)
        {
            Ice._ObjectDel __delBase = null;
            try
            {
                __checkTwowayOnly("getPoints");
                __delBase = __getDelegate(false);
                _AirportInterfaceDel __del = (_AirportInterfaceDel)__delBase;
                return __del.getPoints(__ctx);
            }
            catch(IceInternal.LocalExceptionWrapper __ex)
            {
                __cnt = __handleExceptionWrapperRelaxed(__delBase, __ex, null, __cnt);
            }
            catch(Ice.LocalException __ex)
            {
                __cnt = __handleException(__delBase, __ex, null, __cnt);
            }
        }
    }

    private static final String __getPoints_name = "getPoints";

    public Ice.AsyncResult begin_getPoints()
    {
        return begin_getPoints(null, false, null);
    }

    public Ice.AsyncResult begin_getPoints(java.util.Map<String, String> __ctx)
    {
        return begin_getPoints(__ctx, true, null);
    }

    public Ice.AsyncResult begin_getPoints(Ice.Callback __cb)
    {
        return begin_getPoints(null, false, __cb);
    }

    public Ice.AsyncResult begin_getPoints(java.util.Map<String, String> __ctx, Ice.Callback __cb)
    {
        return begin_getPoints(__ctx, true, __cb);
    }

    public Ice.AsyncResult begin_getPoints(Callback_AirportInterface_getPoints __cb)
    {
        return begin_getPoints(null, false, __cb);
    }

    public Ice.AsyncResult begin_getPoints(java.util.Map<String, String> __ctx, Callback_AirportInterface_getPoints __cb)
    {
        return begin_getPoints(__ctx, true, __cb);
    }

    private Ice.AsyncResult begin_getPoints(java.util.Map<String, String> __ctx, boolean __explicitCtx, IceInternal.CallbackBase __cb)
    {
        __checkAsyncTwowayOnly(__getPoints_name);
        IceInternal.OutgoingAsync __result = new IceInternal.OutgoingAsync(this, __getPoints_name, __cb);
        try
        {
            __result.__prepare(__getPoints_name, Ice.OperationMode.Idempotent, __ctx, __explicitCtx);
            IceInternal.BasicStream __os = __result.__os();
            __os.endWriteEncaps();
            __result.__send(true);
        }
        catch(Ice.LocalException __ex)
        {
            __result.__exceptionAsync(__ex);
        }
        return __result;
    }

    public int end_getPoints(Ice.AsyncResult __result)
    {
        Ice.AsyncResult.__check(__result, this, __getPoints_name);
        if(!__result.__wait())
        {
            try
            {
                __result.__throwUserException();
            }
            catch(Ice.UserException __ex)
            {
                throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
            }
        }
        int __ret;
        IceInternal.BasicStream __is = __result.__is();
        __is.startReadEncaps();
        __ret = __is.readInt();
        __is.endReadEncaps();
        return __ret;
    }

    public float
    getSimT()
    {
        return getSimT(null, false);
    }

    public float
    getSimT(java.util.Map<String, String> __ctx)
    {
        return getSimT(__ctx, true);
    }

    private float
    getSimT(java.util.Map<String, String> __ctx, boolean __explicitCtx)
    {
        if(__explicitCtx && __ctx == null)
        {
            __ctx = _emptyContext;
        }
        int __cnt = 0;
        while(true)
        {
            Ice._ObjectDel __delBase = null;
            try
            {
                __checkTwowayOnly("getSimT");
                __delBase = __getDelegate(false);
                _AirportInterfaceDel __del = (_AirportInterfaceDel)__delBase;
                return __del.getSimT(__ctx);
            }
            catch(IceInternal.LocalExceptionWrapper __ex)
            {
                __cnt = __handleExceptionWrapperRelaxed(__delBase, __ex, null, __cnt);
            }
            catch(Ice.LocalException __ex)
            {
                __cnt = __handleException(__delBase, __ex, null, __cnt);
            }
        }
    }

    private static final String __getSimT_name = "getSimT";

    public Ice.AsyncResult begin_getSimT()
    {
        return begin_getSimT(null, false, null);
    }

    public Ice.AsyncResult begin_getSimT(java.util.Map<String, String> __ctx)
    {
        return begin_getSimT(__ctx, true, null);
    }

    public Ice.AsyncResult begin_getSimT(Ice.Callback __cb)
    {
        return begin_getSimT(null, false, __cb);
    }

    public Ice.AsyncResult begin_getSimT(java.util.Map<String, String> __ctx, Ice.Callback __cb)
    {
        return begin_getSimT(__ctx, true, __cb);
    }

    public Ice.AsyncResult begin_getSimT(Callback_AirportInterface_getSimT __cb)
    {
        return begin_getSimT(null, false, __cb);
    }

    public Ice.AsyncResult begin_getSimT(java.util.Map<String, String> __ctx, Callback_AirportInterface_getSimT __cb)
    {
        return begin_getSimT(__ctx, true, __cb);
    }

    private Ice.AsyncResult begin_getSimT(java.util.Map<String, String> __ctx, boolean __explicitCtx, IceInternal.CallbackBase __cb)
    {
        __checkAsyncTwowayOnly(__getSimT_name);
        IceInternal.OutgoingAsync __result = new IceInternal.OutgoingAsync(this, __getSimT_name, __cb);
        try
        {
            __result.__prepare(__getSimT_name, Ice.OperationMode.Idempotent, __ctx, __explicitCtx);
            IceInternal.BasicStream __os = __result.__os();
            __os.endWriteEncaps();
            __result.__send(true);
        }
        catch(Ice.LocalException __ex)
        {
            __result.__exceptionAsync(__ex);
        }
        return __result;
    }

    public float end_getSimT(Ice.AsyncResult __result)
    {
        Ice.AsyncResult.__check(__result, this, __getSimT_name);
        if(!__result.__wait())
        {
            try
            {
                __result.__throwUserException();
            }
            catch(Ice.UserException __ex)
            {
                throw new Ice.UnknownUserException(__ex.ice_name(), __ex);
            }
        }
        float __ret;
        IceInternal.BasicStream __is = __result.__is();
        __is.startReadEncaps();
        __ret = __is.readFloat();
        __is.endReadEncaps();
        return __ret;
    }

    public static AirportInterfacePrx
    checkedCast(Ice.ObjectPrx __obj)
    {
        AirportInterfacePrx __d = null;
        if(__obj != null)
        {
            try
            {
                __d = (AirportInterfacePrx)__obj;
            }
            catch(ClassCastException ex)
            {
                if(__obj.ice_isA(ice_staticId()))
                {
                    AirportInterfacePrxHelper __h = new AirportInterfacePrxHelper();
                    __h.__copyFrom(__obj);
                    __d = __h;
                }
            }
        }
        return __d;
    }

    public static AirportInterfacePrx
    checkedCast(Ice.ObjectPrx __obj, java.util.Map<String, String> __ctx)
    {
        AirportInterfacePrx __d = null;
        if(__obj != null)
        {
            try
            {
                __d = (AirportInterfacePrx)__obj;
            }
            catch(ClassCastException ex)
            {
                if(__obj.ice_isA(ice_staticId(), __ctx))
                {
                    AirportInterfacePrxHelper __h = new AirportInterfacePrxHelper();
                    __h.__copyFrom(__obj);
                    __d = __h;
                }
            }
        }
        return __d;
    }

    public static AirportInterfacePrx
    checkedCast(Ice.ObjectPrx __obj, String __facet)
    {
        AirportInterfacePrx __d = null;
        if(__obj != null)
        {
            Ice.ObjectPrx __bb = __obj.ice_facet(__facet);
            try
            {
                if(__bb.ice_isA(ice_staticId()))
                {
                    AirportInterfacePrxHelper __h = new AirportInterfacePrxHelper();
                    __h.__copyFrom(__bb);
                    __d = __h;
                }
            }
            catch(Ice.FacetNotExistException ex)
            {
            }
        }
        return __d;
    }

    public static AirportInterfacePrx
    checkedCast(Ice.ObjectPrx __obj, String __facet, java.util.Map<String, String> __ctx)
    {
        AirportInterfacePrx __d = null;
        if(__obj != null)
        {
            Ice.ObjectPrx __bb = __obj.ice_facet(__facet);
            try
            {
                if(__bb.ice_isA(ice_staticId(), __ctx))
                {
                    AirportInterfacePrxHelper __h = new AirportInterfacePrxHelper();
                    __h.__copyFrom(__bb);
                    __d = __h;
                }
            }
            catch(Ice.FacetNotExistException ex)
            {
            }
        }
        return __d;
    }

    public static AirportInterfacePrx
    uncheckedCast(Ice.ObjectPrx __obj)
    {
        AirportInterfacePrx __d = null;
        if(__obj != null)
        {
            try
            {
                __d = (AirportInterfacePrx)__obj;
            }
            catch(ClassCastException ex)
            {
                AirportInterfacePrxHelper __h = new AirportInterfacePrxHelper();
                __h.__copyFrom(__obj);
                __d = __h;
            }
        }
        return __d;
    }

    public static AirportInterfacePrx
    uncheckedCast(Ice.ObjectPrx __obj, String __facet)
    {
        AirportInterfacePrx __d = null;
        if(__obj != null)
        {
            Ice.ObjectPrx __bb = __obj.ice_facet(__facet);
            AirportInterfacePrxHelper __h = new AirportInterfacePrxHelper();
            __h.__copyFrom(__bb);
            __d = __h;
        }
        return __d;
    }

    public static final String[] __ids =
    {
        "::ATCDisplay::AirportInterface",
        "::Ice::Object"
    };

    public static String
    ice_staticId()
    {
        return __ids[0];
    }

    protected Ice._ObjectDelM
    __createDelegateM()
    {
        return new _AirportInterfaceDelM();
    }

    protected Ice._ObjectDelD
    __createDelegateD()
    {
        return new _AirportInterfaceDelD();
    }

    public static void
    __write(IceInternal.BasicStream __os, AirportInterfacePrx v)
    {
        __os.writeProxy(v);
    }

    public static AirportInterfacePrx
    __read(IceInternal.BasicStream __is)
    {
        Ice.ObjectPrx proxy = __is.readProxy();
        if(proxy != null)
        {
            AirportInterfacePrxHelper result = new AirportInterfacePrxHelper();
            result.__copyFrom(proxy);
            return result;
        }
        return null;
    }
}