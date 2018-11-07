#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "Pessoa.h"

void thisIsATest() {
	Farmacia* f1 = new Farmacia("Costa", "Candido dos Reis");
	Funcionario* f = new Funcionario("Pedro", "rua x", 257441883);
	f->setFarmacia(f1);
	f->showInfo();
	Venda* v1 = new Venda();
	for (int i = 0; i < 5000; i++){

	}
	Venda* v2 = new Venda();
	f1->addVenda(v2);
	f1->addVenda(v1);
	enum tipoSort t = DEFAULT;
	f1->sortVendas(t, true);
	ASSERT_EQUAL(f1->getVendas().at(0), v1);
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here
	s.push_back(CUTE(thisIsATest));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}
