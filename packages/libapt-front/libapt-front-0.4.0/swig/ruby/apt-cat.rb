#!/usr/bin/ruby1.8

require "aptfront"

Aptfront::aptFrontInit()
cache = Aptfront::Global::cache()
puts cache
if (not cache.openCacheFile(Aptfront::OpProgress.new(), Aptfront::Cache::OpenReadOnly))
  puts "Error opening cache"
  error = Aptfront::getGlobalError()
  error.DumpErrors()
end

cache.openRecordsCache
pc = cache.packageCache
pl = pc.packageList

pl.each { |it|
  puts "Package: " + it.name
  #puts "Candidate Version: " + it.candidateVersion.versionString
  it.versionList.each { |v|
    puts "Version: " + v.versionString + (v == it.candidateVersion ? " (candidate)" : '') + (v == it.currentVersion ? " (current)" : '')
    puts "Section: " + v.section
    puts "Architecture: " + v.architecture
    puts "Description: " + v.shortDescription + v.longDescription
  }
  puts
}
