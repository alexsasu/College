import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { PcComponentsComponent } from './pc-components/pc-components.component';
import { PcComponentsRoutingModule } from './pc-components-routing.module';
import { MaterialModule } from '../material/material.module';
// import { PcComponentComponent } from './pc-component/pc-component.component';
import { SharedModule } from '../shared/shared.module';
import { PcPartComponent } from './pc-part/pc-part.component';
// import { PcPartComponent } from './pc-part/pc-part.component';
// import { MarksPipe } from 'src/app/marks.pipe';

@NgModule({
  declarations: [
    PcComponentsComponent,
    PcPartComponent,
    // PcPartComponent,
    // MarksPipe
  ],
  imports: [
    CommonModule,
    PcComponentsRoutingModule,
    MaterialModule,
    SharedModule
  ],
  exports: [
    // MarksPipe,
    SharedModule
  ]
})
export class PcComponentsModule { }
