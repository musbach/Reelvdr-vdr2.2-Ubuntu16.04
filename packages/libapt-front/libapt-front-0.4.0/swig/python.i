%include <file.i>
%include <std_set.i>
%include <std_string.i>

%extend aptFront::cache::component::Packages {
    %pythoncode %{
    def __iter__(self):
        current = Package(self.PkgBegin())
        while True:
            if not current.valid():
                return
            yield current
            current = current.nextInCache()
    %}
};

%extend aptFront::cache::entity::Package {
    %pythoncode %{
    def __iter__(self):
        current = self.firstVersionInCache()
        while True:
            if not current.valid():
                return
            yield current
            current = current.nextInCache()

    versions = __iter__
    %}
};