import { ComponentFixture, TestBed } from '@angular/core/testing';

import { PcComponentsComponent } from './pc-components.component';

describe('PcComponentsComponent', () => {
  let component: PcComponentsComponent;
  let fixture: ComponentFixture<PcComponentsComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ PcComponentsComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(PcComponentsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
