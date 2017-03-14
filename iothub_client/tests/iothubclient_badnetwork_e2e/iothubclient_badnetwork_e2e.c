// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "testrunnerswitcher.h"


static TEST_MUTEX_HANDLE g_dllByDll;

BEGIN_TEST_SUITE(iothubclient_badnetwork_e2e)

    TEST_SUITE_INITIALIZE(TestClassInitialize)
    {
        TEST_INITIALIZE_MEMORY_DEBUG(g_dllByDll);
    }

    TEST_SUITE_CLEANUP(TestClassCleanup)
    {
        TEST_DEINITIALIZE_MEMORY_DEBUG(g_dllByDll);
    }

    TEST_FUNCTION_CLEANUP(TestFunctionCleanup)
    {
    }

    TEST_FUNCTION(IotHub_BadNetwork_EmptyTest)
    {
    }

END_TEST_SUITE(iothubclient_badnetwork_e2e)

