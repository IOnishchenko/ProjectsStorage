#ifndef IVALUE_PROVIDER_H
#define IVALUE_PROVIDER_H

#include "stdint.h"

template<typename VType>
class IValue
{
public:
	// destructor
	virtual ~IValue() = default;

	// methods
	virtual VType GetMaxValue() const = 0;
	virtual VType GetMinValue() const = 0;
	virtual uint32_t GetNumberOfSteps() const = 0;
	virtual VType GetValue() const = 0;
	virtual VType GetValueAt(uint32_t index) const = 0;
	virtual void SetValueByIndex(uint32_t index) = 0;
	virtual uint32_t GetCurrentValueIndex() const = 0;
};

#endif // VALUE_PROVIDER_H