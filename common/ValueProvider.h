#ifndef VALUE_PROVIDER_H
#define VALUE_PROVIDER_H

#include "IValueProvider.h"

template<typename VType>
class ValueProvider : public IValueProvider<VType>
{
public:
	// ValueProvider
	ValueProvider(VType max, VType min, VType step, uint32_t currentIndex)
		:stepIndex_{currentIndex}, max_{max}, min_{min}, step_{step}
	{		
	}

	// destructor
	~ValueProvider() override = default;

	// methods
	VType GetMaxValue() const override
	{
		return max_;
	}

	VType GetMinValue() const override
	{
		return min_;
	}

	uint32_t GetNumberOfSteps() const override
	{
		return (max_ - min_)/step_;
	}

	VType GetValue() const override
	{
		return reinterpret_cast<VType>(stepIndex_) * step_ + min_;
	}

	void SetCurrentIndex(uint32_t index) override
	{
		stepIndex_ = index;
	}

	uint32_t GetCurrentIndex() const override
	{
		return stepIndex_;
	}

	VType GetValueAt(uint32_t index) const override
	{
		return reinterpret_cast<VType>(index) * step_ + min_;
	}

private:
	uint32_t stepIndex_;
	const VType max_;
	const VType min_;
	const VType step_; 
};

#endif // VALUE_WITH_RANGE_H