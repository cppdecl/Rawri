#ifndef __RAWRI__DATASTORE__HH__
#define __RAWRI__DATASTORE__HH__

#include <stdexcept> 
#include <memory>
#include <type_traits>
#include <unordered_map>

class DataStore
{
   public:
	template <typename T>
	void Set(const std::string& id, const T& data)
	{
		m_Data[id] = std::make_unique<DataStoreHolder<T>>(data);
	}

	bool Find(const std::string& id)
	{
		auto it = m_Data.find(id);
		if (it == m_Data.end())
		{
			return false;
		}

		return true;
	}

	void Remove(const std::string& id)
	{
		auto it = m_Data.find(id);
		if (it == m_Data.end())
		{
			return;
		}

		m_Data.erase(it);
	}

	template <typename T>
	typename std::enable_if<!std::is_void<T>::value, T>::type Get(const std::string& id) const
	{
		auto it = m_Data.find(id);
		if (it == m_Data.end())
		{
			throw std::out_of_range("ID \"" + id + "\" not found from DataStore.");
		}

		auto holder = dynamic_cast<DataStoreHolder<T>*>(it->second.get());
		if (!holder)
		{
			throw std::invalid_argument("Type mismatch in DataStore.");
		}

		return holder->data;
	}

	template <typename T>
	typename std::enable_if<std::is_void<T>::value>::type Get(const std::string& id) const
	{
		auto it = m_Data.find(id);
		if (it == m_Data.end())
		{
			throw std::out_of_range("ID \"" + id + "\" not found from DataStore.");
		}
		auto holder = dynamic_cast<DataStoreHolder<T>*>(it->second.get());
		if (!holder)
		{
			throw std::invalid_argument("Type mismatch in DataStore.");
		}
	}

	template <typename T>
	typename std::enable_if<!std::is_void<T>::value, std::string>::type GetType(const std::string& id) const
	{
		auto it = m_Data.find(id);
		if (it == m_Data.end())
		{
			throw std::out_of_range("ID \"" + id + "\" not found from DataStore.");
		}

		auto holder = dynamic_cast<DataStoreHolder<T>*>(it->second.get());
		if (!holder)
		{
			throw std::invalid_argument("Type mismatch in DataStore.");
		}

		return typeid(T).name();
	}

	size_t GetSize(const std::string& id) const
	{
		auto it = m_Data.find(id);
		if (it == m_Data.end())
		{
			throw std::out_of_range("ID \"" + id + "\" not found from DataStore.");
		}

		auto holder = it->second.get();
		if (!holder)
		{
			throw std::invalid_argument("Type mismatch in DataStore.");
		}

		return  sizeof(*holder);
	}

	size_t GetMemoryUsage(bool redundancy = false) const
	{
		size_t totalSize = 0;
		for (auto& kv : m_Data)
		{
			totalSize += GetSize(kv.first);
		}

		if (redundancy)
		{
			totalSize *= 2;
		}

		return totalSize;
	}

	void Reset()
	{
		m_Data.clear();
	}

   private:
	class DataStoreHolderBase
	{
	   public:
		virtual ~DataStoreHolderBase()
		{
		}
	};

	template <typename T>
	class DataStoreHolder : public DataStoreHolderBase
	{
	   public:
		DataStoreHolder(const T& data) : data(data)
		{
		}
		T data;
	};

	std::unordered_map<std::string, std::unique_ptr<DataStoreHolderBase>> m_Data;
};

#endif	// __RAWRI__DATASTORE__HH__