#pragma once

struct IFile {
	virtual void loadDynamicLibrary() = 0;

	typedef std::function<void(const std::string& /*filename*/)> LockCallback;
	virtual void lock(const LockCallback& callback) = 0;
};