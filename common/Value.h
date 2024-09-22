#ifndef VALUE_PROVIDER_H
#define VALUE_PROVIDER_H

#include "IValue.h"

template<typename VType>
class Value : public IValue<VType>
{
public:
	// constructor
	Value(VType min, VType max, VType step, uint32_t currentIndex)
		:stepIndex_{currentIndex}, max_{max}, min_{min}, step_{step}
	{		
	}

	// destructor
	~Value() override = default;

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
		return stepIndex_ * step_ + min_;
	}

	void SetValueByIndex(uint32_t index) override
	{
		stepIndex_ = index;
	}

	uint32_t GetIndex() const override
	{
		return stepIndex_;
	}

	VType GetValueAt(uint32_t index) const override
	{
		return index * step_ + min_;
	}

private:
	uint32_t stepIndex_;
	const VType max_;
	const VType min_;
	const VType step_; 
};

#endif // VALUE_WITH_RANGE_H