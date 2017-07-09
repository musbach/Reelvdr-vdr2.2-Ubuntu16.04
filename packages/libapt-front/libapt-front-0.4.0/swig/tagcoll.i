%{
#include <tagcoll/OpSet.h>
#include <tagcoll/Serializer.h>
#include <tagcoll/Consumer.h>
#include <tagcoll/Collection.h>
#include <tagcoll/StdioParserInput.h>
#include <tagcoll/InputMerger.h>
#include <tagcoll/InputMerger.cc> // needed for InputMerger<string, Tag>
#include <tagcoll/PatchCollection.h>
#include <tagcoll/TDBReadonlyDiskIndex.h>
#include <tagcoll/TextFormat.h>
#include <tagcoll/Filter.h>
#include <tagcoll/Expression.h>
#include <tagcoll/experiments.h>
%}

%include <tagcoll/OpSet.h>
%include <tagcoll/Serializer.h>
%include <tagcoll/Consumer.h>
%include <tagcoll/Collection.h>
%include <tagcoll/StdioParserInput.h>
%include <tagcoll/InputMerger.h>
%include <tagcoll/PatchCollection.h>
%include <tagcoll/TDBReadonlyDiskIndex.h>
%include <tagcoll/TextFormat.h>
%include <tagcoll/Filter.h>
%include <tagcoll/Patches.h>
%include <tagcoll/Expression.h>
%include <tagcoll/experiments.h>

// naming conventions for the templates:
// if the template arguments are Package, Tag then
// prefix the class with Debtags, otherwise append
// _x for type suffixes (T = Tag, F = Facet, s = std::string, P = Package etc)

// if a class should not be instantiated by the user, prefix it with
// one (!) leading underscore (note: __ breaks Python, since __-prefixed members
// get mangled names)

// NOTE: it seems to be necessary that %feature(director) declarations have to occur
// before %template definitions.


/* Template instantiations for std::set and Tagcoll::OpSet */
%template(_stdset_T) std::set<aptFront::cache::entity::Tag>;
%template(_stdset_F) std::set<aptFront::cache::entity::Facet>;
%template(_stdset_s) std::set<std::string>;

%template(_OpSet_T) Tagcoll::OpSet<aptFront::cache::entity::Tag>;
%template(_OpSet_F) Tagcoll::OpSet<aptFront::cache::entity::Facet>;
%template(_OpSet_s) Tagcoll::OpSet<std::string>;


%template(Converter_P_s) 
  Tagcoll::Converter<aptFront::cache::entity::Package,
                     std::string>;
%template(Converter_T_s)
  Tagcoll::Converter<aptFront::cache::entity::Tag,
                     std::string>;
%template(Converter_s_s)
  Tagcoll::Converter<std::string,
                     std::string>;
%template(Converter_s_P)
  Tagcoll::Converter<std::string,
                     aptFront::cache::entity::Package>;
%template(Converter_s_T)
  Tagcoll::Converter<std::string,
                     aptFront::cache::entity::Tag>;


/* enable multi-language polymorphism for Tagcoll::Consumer */
/* needs directors="1" and dirprot="1" in %module */
%feature("director")
  Tagcoll::Consumer<aptFront::cache::entity::Package,
                    aptFront::cache::entity::Tag>;
%feature("director")
  Tagcoll::Consumer<aptFront::cache::entity::Package,
                    aptFront::cache::entity::Facet>;
%feature("director")
  Tagcoll::Consumer<std::string,
                    std::string>;

%feature("director")
  Tagcoll::Consumer<std::string,
                    aptFront::cache::entity::Tag>;

%template(DebtagsConsumer)
  Tagcoll::Consumer<aptFront::cache::entity::Package,
                    aptFront::cache::entity::Tag>;
%template(Consumer_s_s)
  Tagcoll::Consumer<std::string,
                    std::string>;
%template(Consumer_P_F)
  Tagcoll::Consumer<aptFront::cache::entity::Package,
                    aptFront::cache::entity::Facet>;
%template(Consumer_s_T)
  Tagcoll::Consumer<std::string,
                    aptFront::cache::entity::Tag>;


%template(_DebtagsCollection)
  Tagcoll::Collection<aptFront::cache::entity::Package,
                      aptFront::cache::entity::Tag>;
%template(_Collection_s_T)
  Tagcoll::Collection<std::string,
                      aptFront::cache::entity::Tag>;


%template(InputMerger_s_T)
  Tagcoll::InputMerger<std::string,
                       aptFront::cache::entity::Tag>;


%template(DebtagsInputMerger)
  Tagcoll::InputMerger<aptFront::cache::entity::Package,
                       aptFront::cache::entity::Tag>;


%template(_DebtagsPatchCollection)
  Tagcoll::PatchCollection<aptFront::cache::entity::Package,
                           aptFront::cache::entity::Tag>;


%template(_DebtagsReadOnlyIndex)
  Tagcoll::TDBReadonlyDiskIndex<aptFront::cache::entity::Package,
                                aptFront::cache::entity::Tag>;

%template(DebtagsTextFormat)
  Tagcoll::TextFormat<aptFront::cache::entity::Package,
                      aptFront::cache::entity::Tag>;
%template(TextFormat_s_s)
  Tagcoll::TextFormat<std::string,
                      std::string>;

%feature("director")
  Tagcoll::Filter<aptFront::cache::entity::Package,
                  aptFront::cache::entity::Tag>;


%template(_DebtagsFilter)
  Tagcoll::Filter<aptFront::cache::entity::Package,
                  aptFront::cache::entity::Tag>;


%template(DebtagsPatchList)
  Tagcoll::PatchList<aptFront::cache::entity::Package,
                     aptFront::cache::entity::Tag>;

%template(DebtagsPatch)
  Tagcoll::Patch<aptFront::cache::entity::Package,
                 aptFront::cache::entity::Tag>;


%feature ("director")
  Tagcoll::FilterItemsByExpression<aptFront::cache::entity::Package,
                                   aptFront::cache::entity::Tag>;

%template(DebtagsFilterItemsByExpression)
  Tagcoll::FilterItemsByExpression<aptFront::cache::entity::Package,
                                   aptFront::cache::entity::Tag>;

%template(applyToTag) Tagcoll::Expression::operator()<aptFront::cache::entity::Tag>;

%template(TagScores)
  Tagcoll::Scores<aptFront::cache::entity::Tag>;
