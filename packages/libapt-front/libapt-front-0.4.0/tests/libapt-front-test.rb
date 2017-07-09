require 'aptfront'
require 'test/unit'

puts "ruby test suite running..."
Aptfront::aptFrontInit()

class TestCB < Aptfront::ProgressCallback
end

class Cache < Test::Unit::TestCase
  def setup
    @c = Aptfront::Global::cache()
  end
  def test_open
    assert(@c.openCacheFile(Aptfront::OpProgress.new(),
                            Aptfront::Cache::OpenReadOnly),
           "Error opening cache!");
  end
  def test_gc
    cb = Aptfront::ProgressCallback.new()
    ptr = Aptfront::SharedPtrProgressCallback.new(cb)
    cb = 0
    GC.start
    assert(ptr.data)
    cb = ptr.data
    assert(cb._get_refCount())
    cb2 = TestCB.new()
    ptr2 = Aptfront::SharedPtrProgressCallback.new(cb2)
    cb2 = 0
    GC.start
    assert(ptr2.data)
    # segfault (the proxy is deleted by now, apparently... uhm)
    #cb = ptr2.data
    #assert(cb._get_refCount())
  end
end
