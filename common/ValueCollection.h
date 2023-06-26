#ifndef VALUE_COLLECTION_H
#define VALUE_COLLECTION_H

#include <initializer_list>
#include "IValueProvider.h"

template<typename VType, uint32_t ItemNum>
class ValueCollection : public IValueProvider<VType>
{
// constructor
	ValueCollection(uint32_t valueIndex, std::initializer_list<VType> values)
		:valueIndex_{valueIndex}
	{
		int i = 0;
		for(auto itm : values)
		{
			items_[i++] = itm;
		}
	}

	// destructor
	~ValueCollection() override = default;

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

	void SetCurrentIndex(uint32_t index) override
	{
		valueIndex_ = index;
	}

	uint32_t GetCurrentIndex() const override
	{
		return valueIndex_;
	}

	VType GetValueAt(uint32_t index) const override
	{
		return items_[index];
	}

private:
	uint32_t valueIndex_;
	const VType items_[ItemNum];
};

#endif // VALUE_COLLECTION_H