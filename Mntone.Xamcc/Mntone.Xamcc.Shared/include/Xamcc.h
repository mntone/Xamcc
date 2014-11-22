#pragma once

#ifndef XAMCC_YOUR_ROOT_NAMESPACE_BEGIN
#define XAMCC_YOUR_ROOT_NAMESPACE_BEGIN namespace Mntone {
#endif

#ifndef XAMCC_YOUR_ROOT_NAMESPACE_END
#define XAMCC_YOUR_ROOT_NAMESPACE_END }
#endif

#include "Preprocessor\PropertyPreprocessor.h"
#include "Preprocessor\DependencyObjectPreprocessor.h"

#include "Foundation\TimeSpanReference.h"
#include "Foundation\EventWrapper.h"

#include "Commands\RelayCommand.h"
#include "Commands\RelayCommand.generic.h"

#include "DependencyObjectCollectionCpp.h"
#include "DispatcherHelper.h"
#include "ViewModelHelper.h"