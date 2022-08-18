import 'package:get/get.dart';

import 'controllers/controller.dart';

class ControllerBindings extends Bindings {
  @override
  void dependencies() {
    Get.put<APIcontroller>(APIcontroller());
    Get.put<QuestionController>(QuestionController());
  }
}