#ifndef VALUE_TABLE_H
#define VALUE_TABLE_H

#include <initializer_list>
#include <array>
#include "IValue.h"

template<typename VType, uint32_t ItemNum>
class ValueTable : public IValue<VType>
{
public:
	// constructor
	ValueTable(uint32_t valueIndex, const std::array<VType, ItemNum> & values)
		:valueIndex_{valueIndex}, items_{values}
	{
	}

	// destructor
	~ValueTable() override = default;

	// methods
	VType GetMaxValue() const override
	{
		return items_[0];
	}

	VType GetMinValue() const override
	{
		return items_[ItemNum-1];
	}

	uint32_t GetNumberOfSteps() const override
	{
		return ItemNum;
	}

	VType GetValue() const override
	{
		return items_[valueIndex_];
	}

	void SetValueByIndex(uint32_t index) override
	{
		valueIndex_ = index;
	}

	uint32_t GetCurrentValueIndex() const override
	{
		return valueIndex_;
	}

	VType GetValueAt(uint32_t index) const override
	{
		return items_[index];
	}

private:
	uint32_t valueIndex_;
	const std::array<VType, ItemNum> items_;
};

#endif // VALUE_TABLE_H