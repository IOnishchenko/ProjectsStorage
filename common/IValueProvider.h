#ifndef IVALUE_PROVIDER_H
#define IVALUE_PROVIDER_H

template<typename VType>
class IValueProvider
{
public:
	// destructor
	virtual ~IValueProvider() = default;

	// methods
	virtual VType GetMaxValue() const = 0;
	virtual VType GetMinValue() const = 0;
	virtual uint32_t GetNumberOfSteps() const = 0;
	virtual VType GetValue() const = 0;
	virtual void SetCurrentIndex(uint32_t index) = 0;
	virtual uint32_t GetCurrentIndex() const = 0;
	virtual VType GetValueAt(uint32_t index) const = 0;
};

#endif // VALUE_PROVIDER_H