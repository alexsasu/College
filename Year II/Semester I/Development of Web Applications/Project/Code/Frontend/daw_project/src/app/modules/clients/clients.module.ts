import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { ClientsComponent } from './clients/clients.component';
import { ClientsRoutingModule } from './clients-routing.module';
import { ChildComponent } from './child/child.component';
import { MaterialModule } from '../material/material.module';
import { ClientComponent } from './client/client.component';
import { SharedModule } from '../shared/shared.module';
// import { MarksPipe } from 'src/app/marks.pipe';

@NgModule({
  declarations: [
    ClientsComponent,
    ChildComponent,
    ClientComponent,
    // MarksPipe
  ],
  imports: [
    CommonModule,
    ClientsRoutingModule,
    MaterialModule,
    SharedModule
  ],
  exports: [
    // MarksPipe
    SharedModule
  ]
})
export class ClientsModule { }
