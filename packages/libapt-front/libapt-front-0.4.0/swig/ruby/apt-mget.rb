#!/usr/bin/ruby1.8

require "aptfront"

class MyProgressCallback < Aptfront::ProgressCallback
  def UpdatePulse(a, b, c)
    printf "\rUpdatePulse %d %d %d                    ", a, b, c
  end
end

Aptfront::aptFrontInit()
cache = Aptfront::CacheGlobal::cache()
puts cache
if (not cache.openCacheFile(Aptfront::OpProgress.new(), Aptfront::Cache::OpenReadOnly))
  puts "Error opening cache"
  error = Aptfront::getGlobalError()
  error.DumpErrors()
end

cache.openRecordsCache()

pm = Aptfront::PackageManager.new(cache)
callback = MyProgressCallback.new()
ptr = Aptfront::SharedPtrProgressCallback.new(callback)
pm.setProgressCallback(ptr)
puts ptr.data()
pm.update()
Aptfront::getGlobalError().DumpErrors()
